
def level_of_tensorize(info):
    """
    Function which search the level where we can cut to tensorize.
    If it is the second time we have a variable or it is a reduction loop
    we tensorize at this level
    """
    dic = {
        'y': 0,
        'x': 0,
        'f': 0,
        'c': 0,
        'h': 0,
        'w': 0
    }

    for k in range(len(info)):
        if "for" == info[k][0]:
            variable = info[k][4][0][0]
            if "y" in variable:
                if dic["y"] == 1:
                    return k
                else:
                    dic["y"] += 1
            if "x" in variable:
                if dic["x"] == 1:
                    return k
                else:
                    dic["x"] += 1
            if "f" in variable:
                if dic["f"] == 1:
                    return k
                else:
                    dic["f"] += 1
            if "c" in variable:
                if dic["c"] == 1:
                    return k
                else:
                    dic["c"] += 1
            if "h" in variable:
                return k
            if "w" in variable:
                return k
    return 0

def write_c_file(name, header, old_file, info, suffix_name_fct = ""):

    """
    Function which write the C files for tensorize
    """

    f = open(name, "w")
    f.write("""
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
    """)
    for k in range(header):
        if ") {" in old_file[k]:
            f.write(old_file[k].replace(") {", ", int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {"))
        elif "assert" in old_file[k] or "#include" in old_file[k]:
            continue
        elif "gen_conv" in old_file[k]:
            new_name_fct = "gen_conv" + suffix_name_fct
            f.write(old_file[k].replace("gen_conv", new_name_fct))
        else:
            f.write(old_file[k])

    level_ = level_of_tensorize(info)

    # we need to init value of delete loop
    for i in range(level_):
        if info[i][0] == 'for':
            for j in range(len(info[i][4][0])):
                f.write(info[i][4][0][j].replace(" ", "") + " = 0;\n")

    # begin and end of line to write
    begin = info[level_][1]
    end = info[level_][2]

    for k in range(begin, end + 1):
        f.write(old_file[k])

    f.write("}\n") # for the main

    f.close()

    return level_

def replace(f, x, y):
    """
    Function to replace all element x by y in the list f
    """
    for k in range(10, len(f)):
        if x in f[k]:
            f[k] = f[k].replace(x, y)
    return f

def factor(variable, structure):
    """
    Return the factor of each tile
    """
    f = []
    if variable == "height":
        for k in range(1, len(structure)):
            l = structure[k][4]
            if "y" in l[0][0]:
                return l[1]
    for k in range(1, len(structure)):
        l = structure[k][4]
        if variable in l[0][0]:
            f += [l[2]]
    return f

def order(structure, suffix=""):
    """
    Return the loop order of the convolution
    """
    outter = 'o'
    inner = 'i'
    order = []
    convert = {
        "f": "axe_out_channels" + suffix,
        "c": "axe_in_channels" + suffix,
        "x": "axe_xx" + suffix,
        "y": "axe_yy" + suffix,
        "w": "axe_kernel_w" + suffix,
        "h": "axe_kernel_h" + suffix
    }
    number = {
        "f": 0,
        "c": 0,
        "x": 0,
        "y": 0,
        "w": 0,
        "h": 0
    }
    for k in range(1, len(structure)):
        l = structure[k][4]
        if "x" in l[0][0]:
            variable = "x"
        elif "y" in l[0][0]:
            variable = "y"
        elif "h" in l[0][0]:
            variable = "h"
        elif "w" in l[0][0]:
            variable = "w"
        elif "f" in l[0][0]:
            variable = "f"
        elif "c" in l[0][0]:
            variable = "c"
        suffix_loop = str(number[variable])
        order += [convert[variable] + "_" + suffix_loop]
        number[variable] += 1

    return order

def find_loop_to_delete(structure, id):
    """
    Find the index in structure where level == id
    """
    index = []
    for k in range(len(structure)):
        if structure[k][3] == id:
            index += [k]
    return index

def delete_loop(f, begin, end):
    """
    Delete a part of f between begin and end
    """
    for k in range(end, begin - 1, -1):
        del f[k]
    return f

def compute_structure(f):

    """
    Compute the structure of f.
    If there are two micro kernels we divide the file in two files and compute
    the structure for each files.
    """

    nb_file = 1
    f1 = None
    f2 = None

    def compute_structure_(f):
        """
        Compute the structure of file f

        structure
         [
            {main, for, if}
            line of beginning
            line of end
            level of loop
            [
                [variables]
                end of this variable
                increment
            ]

         ]
        """
        structure = []
        number_bracketl = 0 #{
        number_bracketr = 0 #}
        level = 0 # level of loop

        pile_bracket = [] # pile to associate each bracket
        for k in range(len(f)):
            if "{" in f[k]:
                if "for" in f[k]:
                    # loop is a list of element inside the declaration of the loop
                    loop = f[k].split(")")[0].split("(")[1].split(";")
                    v = []
                    v2 = []
                    for element in range(len(loop)):
                        v += [loop[element].split(",")[0]]
                        if element == 0:
                            v2 += [loop[element].split(",")[1]]
                    structure += [["for", k, 0, level, [[v[0].split("=")[0], v2[0].split("=")[0]], int(v[1].split("+")[-1]), int(v[2].split("+=")[1])]]]
                    number_bracketl += 1
                    level += 1
                else:
                    structure += [["main", k, 0, level]]
                    number_bracketl += 1
                    level += 1
                pile_bracket.append(len(structure) - 1)
            if "}" in f[k]:
                level -= 1
                id = pile_bracket.pop()
                structure[id][2] = k
        return structure

    s_ = compute_structure_(f)

    # I search the number of loop level i.e. if I need to have one or two files
    number_of_level = [0 for k in range(20)]
    for k in range(len(s_)):
        if s_[k][0] == "for":
            number_of_level[int(s_[k][3])] += 1
    try:
        index_dedoublement = number_of_level.index(2)
    except:
        # that mean we do not have 2 levels
        return 1, f, s_, None, None

    # This part we have two files
    x, y = find_loop_to_delete(s_, index_dedoublement)
    f2 = delete_loop(f.copy(), s_[x][1], s_[x][2])
    f1 = delete_loop(f.copy(), s_[y][1], s_[y][2])

    structure1 = compute_structure_(f1)
    structure2 = compute_structure_(f2)

    return 2, f1, structure1, f2, structure2


def parser(name):

    """
    Function which parse C file to create new C files for tensorize

     Return a dic with factor of tille
    """

    # open the C file
    file_ = open("c_files/" + name + ".c", "r")
    f = file_.readlines()
    file_.close()

    # I change the code to create the for on one line
    delete = []
    for k in range(len(f)):
        if "for" in f[k]:
            f[k] = f[k].split("\n")[0] + f[k+1].split("\n")[0].replace("\t", "") + f[k+2].split("\n")[0].replace("\t", "") + "\n" #faut supprimer les tabs
            delete += [k+1]
            delete += [k+2]
        if list(f[k]) == ["\n"]:
            delete += [k]

    # we delete the part useless of for
    # order is important like we delete
    for k in range(len(delete)):
        del f[delete[-k - 1]]

    # I replace old strides by new ones
    # order is important
    f = replace(f, "(F * Y)", "strideO1")
    f = replace(f, "((F * C) * H)", "strideW1")
    f = replace(f, "(F * C)", "strideW2")
    f = replace(f, "(C * (Y + H - 1))", "strideA1")
    f = replace(f, "C", "strideA2")
    f = replace(f, "F * c", "strideW3 * c")
    f = replace(f, "F", "strideO2")

    number_of_file, f1, structure1, f2, structure2 = compute_structure(f)

    if number_of_file == 1:
        level1 = write_c_file("tensorize_files/" + name + ".c", structure1[1][1], f1, structure1)

        # information for tensorize i.e. factor of tilling
        info_tensorize = {}

        info_tensorize[1] = {
            "factor_out_channels": factor("f", structure1),
            "factor_xx": factor("x", structure1),
            "factor_yy": factor("y", structure1),
            "factor_in_channels": factor("c", structure1),
            "order": order(structure1),
            "nb_loop_no_tensorize": level1 - 1,
            "axe_to_tensorize": order(structure1)[level1 - 1]
        }

    else:
        level1 = write_c_file("tensorize_files/" + name + "1.c", structure1[1][1], f1, structure1, "1")
        level2 = write_c_file("tensorize_files/" + name + "2.c", structure2[1][1], f2, structure2, "2")

        # information for tensorize i.e. factor of tilling
        info_tensorize = {}

        info_tensorize[1] = {
            "height": factor("height", structure1),
            "factor_out_channels": factor("f", structure1),
            "factor_xx": factor("x", structure1),
            "factor_yy": factor("y", structure1),
            "factor_in_channels": factor("c", structure1),
            "order": order(structure1, "1"),
            "nb_loop_no_tensorize": level1 - 1,
            "axe_to_tensorize": order(structure1, "1")[level1 - 1]
        }
        info_tensorize[2] = {
            "height": factor("height", structure2),
            "factor_out_channels": factor("f", structure2),
            "factor_xx": factor("x", structure2),
            "factor_yy": factor("y", structure2),
            "factor_in_channels": factor("c", structure2),
            "order": order(structure2, "2"),
            "nb_loop_no_tensorize": level2 - 1,
            "axe_to_tensorize": order(structure2, "2")[level2 - 1]
        }
    # for t in structure1:
    #     print(t)
    # print()
    # for t in structure2:
    #     print(t)
    # print(info_tensorize[1])
    # print(info_tensorize[2])



    return info_tensorize
