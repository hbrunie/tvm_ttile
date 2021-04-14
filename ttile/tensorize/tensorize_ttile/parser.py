# Parser

def find_level_max(f):
    """
    Find the level maximum to tensorize
    i.e. when the loop load output
    """
    number_of_for = 0
    for k in f:
        if "for" in k:
            number_of_for += 1
        if "loadu_ps" in k:
            return number_of_for

def level_of_tensorize(info, f):
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

    level_max = find_level_max(f)

    for k in range(len(info)):
        if "for" == info[k][0]:
            variable = info[k][4][0][0]
            if "h" in variable:
                return k
            if "w" in variable:
                return k
            if k >= level_max:
                return k
    return 0

size = {
    "c": 0,
    "f": 0,
    "x": 0,
    "y": 0,
    "h": 0,
    "w": 0,
}

def write_c_file(name, header, old_file, info, suffix_name_fct = "", out_h1 = 0):

    """
    Function which write the C files for tensorize
    """

    f = open(name, "w")
    if suffix_name_fct != "2":
        f.write("""
#include <immintrin.h>
typedef int IND_TYPE;
typedef float M_TYPE;
        """)
    for k in range(header):
        if ") {" in old_file[k]:
            f.write(old_file[k].replace(") {", ", int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {"))
        elif "#include" in old_file[k] or "assert" in old_file[k]:
            continue
        elif "gen_conv" in old_file[k]:
            new_name_fct = "gen_conv" + suffix_name_fct
            f.write(old_file[k].replace("gen_conv", new_name_fct))
        else:
            f.write(old_file[k])

    level_ = level_of_tensorize(info, old_file)

    # we need to init value of delete loop
    for i in range(level_):
        if info[i][0] == 'for':
            for j in range(len(info[i][4][0])):
                f.write(info[i][4][0][j].replace(" ", "") + " = 0;\n")

    # begin and end of line to write
    begin = info[level_][1]
    end = info[level_][2]

    for k in range(begin, end + 1):
        if suffix_name_fct == "2" and "for" in old_file[k] and "y" in old_file[k] and "+ " + str(out_h1) in old_file[k]:
            f.write(old_file[k].replace("+ " + str(out_h1), ""))
        else:
            f.write(old_file[k])

    f.write("}\n") # for the main

    f.close()

    return level_


def write_c_file_special_case(name, header, old_file, info, level_):


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
        elif "#include" in old_file[k] or "assert" in old_file[k]:
            continue
        elif "gen_conv" in old_file[k]:
            new_name_fct = "gen_conv"
            f.write(old_file[k].replace("gen_conv", new_name_fct))
        else:
            f.write(old_file[k])

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


    # To avoid pb with no divisible tile
    new_structure = []
    first_y = True
    first_y_split = True
    split_total = 0
    level = 1
    id_y = 0

    for k in range(len(info)):
        if info[k][0] == 'for':
            if "y" in info[k][4][0][0]:
                if first_y:
                    new_structure += [info[k]]
                    first_y = False
                    level += 1
                else:
                    if first_y_split:
                        new_structure += [info[k]]
                        id_y = k
                        level += 1
                        first_y_split = False
                    else:
                        end_loop = info[k][2]
                        end_iteration = info[k][4][2]

                        info[id_y][2] = end_loop
                        info[id_y][4][2] = end_iteration
                        info[id_y][4][3] = end_iteration

            else:
                if level == info[k][3]:
                    new_structure += [info[k]]
                level += 1

        else:
            new_structure += [info[k]]



    return level_, new_structure

def replace(f, x, y):
    """
    Function to replace all element x by y in the list f
    """
    for k in range(10, len(f)):
        if x in f[k]:
            f[k] = f[k].replace(x, y)
    return f

def factor(variable, order, structure, level_max, split = False):
    """
    Return the factor of each tile
    """
    f = []
    if variable == "height":
        for k in range(1, len(structure)):
            l = structure[k][4]
            if "y" in l[0][0]:
                return l[2] - l[1]

    for k in range(1, len(structure)):
        l = structure[k][4]
        if variable in l[0][0]:
            f += [l[3]]
    v = 0

    convert = {
        "f": "axe_out_channels",
        "c": "axe_in_channels",
        "x": "axe_xx",
        "y": "axe_yy",
        "w": "axe_w",
        "h": "axe_h"
    }

    for k in order:
        if convert[variable] in k:
            v += 1
    if len(f) != 0:
        if len(f) >= v and f[-1] == 1:
            del f[-1]

    return f

def find_size_tensorize(variable, lorder, level, factors, height_y):
    """
    Find the size of variable inside the tensorize function
    """
    letter = variable
    if len(factors) == 0:
        if variable == "y":
            return height_y
        else:
            return size[variable]
    axe_to_tensorize = lorder[level - 1]
    convert = {
        "f": "axe_out_channels",
        "c": "axe_in_channels",
        "x": "axe_xx",
        "y": "axe_yy",
        "w": "axe_w",
        "h": "axe_h"
    }
    variable = convert[variable]
    id_ = 0
    for k in range(level):
        if variable in lorder[k]:
            id_ += 1
    if id_ == 0:
        if letter == "y":
            return height_y
        else:
            return size[letter]
    else:
        if len(factors) == 0:
            return 1
        else:
            return factors[id_ - 1]

def find_loop_to_delete(structure, id_):
    """
    Find the index in structure where level == id
    """
    index = []
    for k in range(len(structure)):
        if structure[k][3] == id_:
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
                begin of this variable
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
                    if len(v[1].split("+")) > 2:
                        bornesup = 0
                        for b in range(len(v[1].split("+")) - 1):
                            bornesup += int(v[1].split("+")[-1 - b])
                    else:
                        bornesup = int(v[1].split("+")[-1])
                    if len(v[0].split("+")) >= 1:
                        borneinf = 0
                        for b in range(len(v[0].split("+")) - 1):
                            borneinf += int(v[0].split("+")[-1 - b])
                    else:
                        borneinf = 0
                    structure += [["for", k, 0, level, [[v[0].split("=")[0], v2[0].split("=")[0]], borneinf, bornesup, int(v[2].split("+=")[1])]]]
                    number_bracketl += 1
                    level += 1
                else:
                    structure += [["main", k, 0, level]]
                    number_bracketl += 1
                    level += 1
                pile_bracket.append(len(structure) - 1)
            if "}" in f[k]:
                level -= 1
                id_ = pile_bracket.pop()
                structure[id_][2] = k
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

    #special case when Y is tile and after split in two
    for k in range(index_dedoublement):
        if s_[k][0] == "for":
            if "y" in s_[k][4][0][0]:
                return 3, f, s_, index_dedoublement, None

    # This part we have two files
    x, y = find_loop_to_delete(s_, index_dedoublement)
    f2 = delete_loop(f.copy(), s_[x][1], s_[x][2])
    f1 = delete_loop(f.copy(), s_[y][1], s_[y][2])

    structure1 = compute_structure_(f1)
    structure2 = compute_structure_(f2)

    return 2, f1, structure1, f2, structure2

def find_fuse(structure, level, order):
    """
    Function to find the fuse
    """
    fuse = []
    fuse_int = []
    nb_iteration = 0
    nb_iteration_fuse = []
    for k in range(level-1):
        begin = structure[k + 1][4][1]
        end = structure[k + 1][4][2]
        split = structure[k + 1][4][3]
        no_useless = (end - begin) // split != 1
        if "in_channels" not in order[k]:
            fuse_int += [order[k]]
            nb_iteration += (end - begin) // split
        else:
            fuse += [fuse_int]
            nb_iteration_fuse += [nb_iteration]
            fuse_int = []
            nb_iteration = 0
    fuse += [fuse_int]
    nb_iteration_fuse += [nb_iteration]
    maxi = 0
    id_max = 0
    for k in range(len(fuse)):
        if nb_iteration_fuse[k] > maxi:
            maxi = nb_iteration_fuse[k]
            id_max = k
    return fuse[id_max], maxi

def order(o, suffix=""):
    """
    Return the loop order of the convolution
    """
    order = []
    convert = {
        "f": "axe_out_channels" + suffix,
        "c": "axe_in_channels" + suffix,
        "x": "axe_xx" + suffix,
        "y": "axe_yy" + suffix,
        "w": "axe_w" + suffix,
        "h": "axe_h" + suffix
    }
    number = {
        "f": 0,
        "c": 0,
        "x": 0,
        "y": 0,
        "w": 0,
        "h": 0
    }

    for k in range(len(o)):
        variable = o[k]
        suffix_loop = str(number[variable])
        order += [convert[variable] + "_" + suffix_loop]
        number[variable] += 1

    return order

def parser(name, stride):

    """
    Function which parse C file to create new C files for tensorize

    Return a dic with factor of tille
    """

    # open the C file
    file_ = open("c_files/" + name + ".c", "r")
    f = file_.readlines()
    file_.close()

    info_orderbegin = 0
    info_orderend = 0
    info_order = ""

    # I change the code to create the for on one line
    delete = []
    for k in range(len(f)):
        if "for" in f[k]:
            f[k] = f[k].split("\n")[0] + f[k+1].split("\n")[0].replace("\t", "") + f[k+2].split("\n")[0].replace("\t", "") + "\n" #faut supprimer les tabs
            delete += [k+1]
            delete += [k+2]
        if list(f[k]) == ["\n"]:
            delete += [k]
        if "assert" in f[k]:
            eq = f[k].split(")")[0].split("(")[-1]
            var, val = eq.split("==")
            var = var.replace(" ", "")
            val = val.replace(" ", "")
            size[var.lower()] = int(val)
        if "/*" in f[k]:
            info_orderbegin = k
        if "*/" in f[k]:
            info_orderend = k

    for k in range(info_orderbegin + 1, info_orderend):
        info_order += f[k]

    info_order = info_order.replace("\n", "")

    info_order_ttile = "".join(info_order.replace(";", ","))

    linfo_order = info_order.split(";")

    info_order = []

    for k in linfo_order:
        if "Hoist_vars" not in k and "V" not in k:
            if "x" in k:
                info_order += ["x"]
            elif "y" in k:
                info_order += ["y"]
            elif "f" in k:
                info_order += ["f"]
            elif "c" in k:
                info_order += ["c"]
            elif "h" in k:
                info_order += ["h"]
            elif "w" in k:
                info_order += ["w"]

    info_order.reverse()

    # we delete the part useless of for
    # order is important like we delete
    for k in range(len(delete)):
        del f[delete[-k - 1]]

    # I replace old strides by new ones
    # order is important
    f = replace(f, "(F * Y)", "strideO1")
    f = replace(f, "((F * C) * H)", "strideW1")
    f = replace(f, "(F * C)", "strideW2")

    if stride == 1:
        f = replace(f, "(C * (Y + H - 1))", "strideA1")
    else:
        f = replace(f, "(C * (2 * Y + H - 1))", "strideA1")
    f = replace(f, "C", "strideA2")
    f = replace(f, "F * c", "strideW3 * c")
    f = replace(f, "F", "strideO2")

    number_of_file, f1, structure1, f2, structure2 = compute_structure(f)


    if number_of_file == 1:
        level1 = write_c_file("tensorize_files/" + name + ".c", structure1[1][1], f1, structure1)

        # information for tensorize i.e. factor of tilling
        info_tensorize = {}

        order1 = order(info_order)
        height1 = size["y"]
        fuse, size_axe_fuse = find_fuse(structure1, level1, order1)

        info_tensorize[1] = {
            "factor_out_channels": factor("f", order1, structure1, level1),
            "factor_xx": factor("x", order1, structure1, level1),
            "factor_yy": factor("y", order1, structure1, level1),
            "factor_h": factor("h", order1, structure1, level1),
            "factor_w": factor("w", order1, structure1, level1),
            "factor_in_channels": factor("c", order1, structure1, level1),
            "order": order1,
            "nb_loop_no_tensorize": level1 - 1,
            "axe_to_tensorize": order1[level1 - 1],
            "h_t": find_size_tensorize("h", order1, level1, [], height1),
            "w_t": find_size_tensorize("w", order1, level1, [], height1),
            "f_t": find_size_tensorize("f", order1, level1, factor("f", order1, structure1, level1), height1),
            "c_t": find_size_tensorize("c", order1, level1, factor("c", order1, structure1, level1), height1),
            "x_t": find_size_tensorize("x", order1, level1, factor("x", order1, structure1, level1), height1),
            "y_t": find_size_tensorize("y", order1, level1, factor("y", order1, structure1, level1), height1),
            "fuse": fuse,
            "size_axe_fuse": size_axe_fuse,
            "schema": info_order_ttile,
        }

    elif number_of_file == 2:

        order1 = order(info_order, "1")
        order2 = order(info_order, "2")

        level1 = write_c_file("tensorize_files/" + name + "1.c", structure1[1][1], f1, structure1, "1")
        out_h1 = factor("height", order1, structure1, level1, True)
        level2 = write_c_file("tensorize_files/" + name + "2.c", structure2[1][1], f2, structure2, "2", out_h1)

        # information for tensorize i.e. factor of tilling
        info_tensorize = {}



        height1 = factor("height", order1, structure1, level1, True)
        height2 = factor("height", order2, structure2, level2, True)

        fuse1, size_axe_fuse1 = find_fuse(structure1, level1, order1)
        fuse2, size_axe_fuse2 = find_fuse(structure2, level2, order2)

        info_tensorize[1] = {
            "height": factor("height", order1, structure1, level1, True),
            "factor_out_channels": factor("f", order1, structure1, level1, True),
            "factor_xx": factor("x", order1, structure1, level1, True),
            "factor_h": factor("h", order1, structure1, level1),
            "factor_w": factor("w", order1, structure1, level1),
            "factor_yy": factor("y", order1, structure1, level1, True),
            "factor_in_channels": factor("c", order1, structure1, level1, True),
            "order": order1,
            "nb_loop_no_tensorize": level1 - 1,
            "axe_to_tensorize": order1[level1 - 1],
            "h_t": find_size_tensorize("h", order1, level1, [], height1),
            "w_t": find_size_tensorize("w", order1, level1, [], height1),
            "f_t": find_size_tensorize("f", order1, level1, factor("f", order1, structure1, level1,  True), height1),
            "c_t": find_size_tensorize("c", order1, level1, factor("c", order1, structure1, level1,  True), height1),
            "x_t": find_size_tensorize("x", order1, level1, factor("x", order1, structure1, level1,  True), height1),
            "y_t": find_size_tensorize("y", order1, level1, factor("y", order1, structure1, level1,  True), height1),
            "fuse": fuse1,
            "size_axe_fuse": size_axe_fuse1,
            "schema": info_order_ttile,
        }
        info_tensorize[2] = {
            "height": factor("height", order2, structure2, level2,  True),
            "factor_out_channels": factor("f", order2, structure2, level2,  True),
            "factor_xx": factor("x", order2, structure2, level2,  True),
            "factor_h": factor("h", order2, structure2, level2),
            "factor_w": factor("w", order2, structure2, level2),
            "factor_yy": factor("y", order2, structure2, level2,  True),
            "factor_in_channels": factor("c", order2, structure2, level2,  True),
            "order": order2,
            "nb_loop_no_tensorize": level2 - 1,
            "axe_to_tensorize": order2[level2 - 1],
            "h_t": find_size_tensorize("h", order2, level2, [], height2),
            "w_t": find_size_tensorize("w", order2, level2, [], height2),
            "f_t": find_size_tensorize("f", order2, level2, factor("f", order2, structure2, level2,  True), height2),
            "c_t": find_size_tensorize("c", order2, level2, factor("c", order2, structure2, level2,  True), height2),
            "x_t": find_size_tensorize("x", order2, level2, factor("x", order2, structure2, level2,  True), height2),
            "y_t": find_size_tensorize("y", order2, level2, factor("y", order2, structure2, level2,  True), height2),
            "fuse": fuse2,
            "size_axe_fuse": size_axe_fuse2,
            "schema": info_order_ttile,
        }

    # special case when y is tile and after split
    else:
        index_dedoublement = f2
        level_to_tensorize = index_dedoublement - 1

        level1, structure1 = write_c_file_special_case("tensorize_files/" + name + ".c", structure1[1][1], f1, structure1, level_to_tensorize)

        # information for tensorize i.e. factor of tilling
        info_tensorize = {}

        order1 = order(info_order)
        height1 = size["y"] 

        fuse, size_axe_fuse = find_fuse(structure1, level1, order1)

        

        level1 -= 1
        info_tensorize[1] = {
            "factor_out_channels": factor("f", order1, structure1, level1),
            "factor_xx": factor("x", order1, structure1, level1),
            "factor_yy": factor("y", order1, structure1, level1),
            "factor_h": factor("h", order1, structure1, level1),
            "factor_w": factor("w", order1, structure1, level1),
            "factor_in_channels": factor("c", order1, structure1, level1),
            "order": order1,
            "nb_loop_no_tensorize": level1 ,
            "axe_to_tensorize": order1[level1 ],
            "h_t": find_size_tensorize("h", order1, level1, [], height1),
            "w_t": find_size_tensorize("w", order1, level1, [], height1),
            "f_t": find_size_tensorize("f", order1, level1, factor("f", order1, structure1, level1), height1),
            "c_t": find_size_tensorize("c", order1, level1, factor("c", order1, structure1, level1), height1),
            "x_t": find_size_tensorize("x", order1, level1, factor("x", order1, structure1, level1), height1),
            "y_t": find_size_tensorize("y", order1, level1, factor("y", order1, structure1, level1), height1),
            "fuse": fuse,
            "size_axe_fuse": size_axe_fuse,
            "schema": info_order_ttile,
        }

    return info_tensorize

#print(parser("MobilNet_5", 1))
