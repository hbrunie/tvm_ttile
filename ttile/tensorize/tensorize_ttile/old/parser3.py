
def flevel(info):
    """
    Function which search the level where we can cut to tensorize
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

def write_c_file(name, header, old_file, info, add_bracketr=1, suffix_name_fct = "", nb_write_just_header = 0):

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

    level_ = flevel(info)
    print("level", level_)
    for i in range(level_):
        if info[i][0] == 'for':
            for j in range(len(info[i][4][0])):
                f.write(info[i][4][0][j].replace(" ", "") + " = 0;\n")
    # pb ici pr
    if suffix_name_fct == "2" and nb_write_just_header != 0:
        for h in range(level_, nb_write_just_header + 1):
            header_for = info[h][1]
            if "\n" in old_file[header_for]:
                f.write(old_file[header_for])
            else:
                f.write(old_file[header_for] + "\n")
        print(level_, nb_write_just_header)
        begin = info[level_ + nb_write_just_header - level_ + 1][1]
        end = info[level_ + nb_write_just_header - level_ + 1][2] + nb_write_just_header - level_ + 1

    else:
        begin = info[level_][1]
        end = info[level_][2]


    for k in range(begin, end + 1):
        if "\n" in old_file[k]:
            f.write(old_file[k])
        else:
            f.write(old_file[k] + "\n")
    if suffix_name_fct == "1":
        add_bracketr = add_bracketr - level_ + 1
    for i in range(add_bracketr): # TODO +/-
        f.write("} //la\n"); # for the main
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
    if variable == "height":
        return structure[1][4][1]
    for k in range(1, len(structure)):
        l = structure[k][4]
        if variable in l[0][0]:
            return l[2]
    return 1

def order(structure, suffix=""): #todo faut verifier qu'il y a pas plus de split que 1
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
        suffix_loop = outter if number[variable] == 0 else inner
        order += [convert[variable] + suffix_loop]
        number[variable] += 1

    return order


def parser(name):

    """
    Function which parse C file to create new C file for tensorize

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

     Return a dic with factor of tille
    """

    # open the C file
    file_ = open("c_files/" + name + ".c", "r")
    f = file_.readlines()
    file_.close()

    # for k in f:
    #     print(k.split("\n"))

    structure = []
    number_bracketl = 0
    number_bracketr = 0
    level = 0


    # I change the code to create the for on one line
    delete = []
    for k in range(len(f)):
        if "for" in f[k]:
            # print(f[k+1])
            f[k] = f[k].split("\n")[0] + f[k+1].split("\n")[0].replace("\t", "") + f[k+2].split("\n")[0].replace("\t", "") #faut supprimer les tabs
            delete += [k+1]
            delete += [k+2]
        if list(f[k]) == ["\n"]:
            delete += [k]

    # we delete the part useless of for
    # order is important like we delete
    for k in range(len(delete)):
        del f[delete[-k - 1]]

    # I create structure
    pile_bracket = []
    for k in range(len(f)):
        if "{" in f[k]:
            if "for" in f[k]:
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
            elif "if" in f[k]:
                structure += [["if", k, 0]]
                number_bracketl += 1
                level += 1
            else:
                structure += [["main", k, 0]]
                number_bracketl += 1
                level += 1
            pile_bracket.append(len(structure) - 1)
        if "}" in f[k]: # pb ici qd ya un dedoublement
            level -= 1
            id = pile_bracket.pop()
            structure[id][2] = k

    s1 = structure.copy()
    s2 = structure.copy()

    # I replace old strides by new ones
    # order is important
    f = replace(f, "(F * Y)", "strideO1")
    f = replace(f, "((F * C) * H)", "strideW1")
    f = replace(f, "(F * C)", "strideW2")
    f = replace(f, "(C * (Y + H - 1))", "strideA1")
    f = replace(f, "C", "strideA2")
    f = replace(f, "F * c", "strideW3 * c")
    f = replace(f, "F", "strideO2")

    # I search the number of loop level i.e. if I need to have one or two files
    number_of_level = [0 for k in range(20)]
    id_level = [0 for k in range(20)]
    for k in range(len(structure)):
        if structure[k][0] == "for":
            number_of_level[int(structure[k][3])] += 1
            id_level[int(structure[k][3])] = k
    try:
        index_dedoublement = number_of_level.index(2)
    except:
        index_dedoublement = -1
    if index_dedoublement == -1:# or index_dedoublement > 4:
        level1 = write_c_file("tensorize_files/" + name + ".c", structure[1][1], f, structure)

        # information for tensorize i.e. factor of tilling
        info_tensorize = {}

        info_tensorize[1] = {
            "factor_out_channels": factor("f", structure),
            "factor_xx": factor("x", structure),
            "factor_yy": factor("y", structure),
            "factor_in_channels": factor("c", structure),
            "order": order(structure),
            "nb_loop_no_tensorize": level1,
            "axe_to_tensorize": order(structure)[level1 - 1]
        }

    else:


        structure1 = s1[:id_level[index_dedoublement]]
        structure2 = [s2[0]]
        for i in range(1, index_dedoublement):
            structure2 += [s2[i]]
        structure2 += s2[id_level[index_dedoublement]:]


        ### ici faut modifier structure car les valeurs de fin de boucle sont plus bonne
        ### yaura un probleme de crochet aussi

        new_index = structure1[index_dedoublement][2]
        print("id", index_dedoublement)
        for dedoublement in range(index_dedoublement):
            structure1[dedoublement][2] = new_index

        number_bracket_to_add = index_dedoublement # +/-
        for key in structure:
            print(key)
        print()
        for kk in structure1:
            print(kk)
        print()
        for kk in structure2:
            print(kk)

        #ici pb avec le deuxieme fichier faut faire un truc avec header

        level1 = write_c_file("tensorize_files/" + name + "1.c", structure[1][1], f, structure1, number_bracket_to_add, "1")
        level2 = write_c_file("tensorize_files/" + name + "2.c", structure[1][1], f, structure2, 1, "2", index_dedoublement - 1)





        # information for tensorize i.e. factor of tilling
        info_tensorize = {}

        info_tensorize[1] = {
            "height": factor("height", structure1),
            "factor_out_channels": factor("f", structure1),
            "factor_xx": factor("x", structure1),
            "factor_yy": factor("y", structure1),
            "factor_in_channels": factor("c", structure1),
            "order": order(structure1, "1"),
            "nb_loop_no_tensorize": level1,
            "axe_to_tensorize": order(structure1, "1")[level1 - 1]
        }
        info_tensorize[2] = {
            "height": factor("height", structure2),
            "factor_out_channels": factor("f", structure2),
            "factor_xx": factor("x", structure2),
            "factor_yy": factor("y", structure2),
            "factor_in_channels": factor("c", structure2),
            "order": order(structure2, "2"),
            "nb_loop_no_tensorize": level2,
            "axe_to_tensorize": order(structure2, "2")[level2 - 1]
        }



    return info_tensorize

# print(parser("n"))
# print()
# print(parser("test2"))
