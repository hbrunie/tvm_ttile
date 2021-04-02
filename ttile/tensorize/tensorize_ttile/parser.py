
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

def write_c_file(name, header, old_file, info):

    """
    Function which write the C files for tensorize
    """

    f = open(name, "w")
    for k in range(header):
        if ") {" in old_file[k]:
            f.write(old_file[k].replace(") {", ", int strideO1, int strideO2, int strideA1, int strideA2, int strideW1, int strideW2, int strideW3) {"))
        elif "assert" in old_file[k]:
            continue
        else:
            f.write(old_file[k])

    level_ = flevel(info)

    for i in range(level_):
        if info[i][0] == 'for':
            for j in range(len(info[i][4][0])):
                f.write(info[i][4][0][j].replace(" ", "") + " = 0;\n")

    begin = info[level_][1]
    end = info[level_][2]

    for k in range(begin, end):
        f.write(old_file[k])

    f.write("}\n"); # for the main

    f.close()

def replace(f, x, y):
    """
    Function to replace all element x by y in the list f
    """
    for k in range(10, len(f)):
        if x in f[k]:
            f[k] = f[k].replace(x, y)
    return f

def factor(variable, structure):
    if variable == "height":
        return structure[1][4][1]
    for k in range(1, len(structure)):
        l = structure[k][4]
        if variable in l[0][0]:
            return l[2]


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

    structure = []
    number_bracketl = 0
    number_bracketr = 0
    level = 0

    # I change the code to create the for on one line
    delete = []
    for k in range(len(f)):
        if "for" in f[k]:
            f[k] = f[k].split("\n")[0] + f[k+1].split("\n")[0].replace("\t", "") + f[k+2].split("\n")[0].replace("\t", "") #faut supprimer les tabs
            delete += [k+1]
            delete += [k+2]

    # we delete the part useless of for
    # order is important like we delete
    for k in range(len(delete)):
        del f[delete[-k - 1]] # pb ici

    # I create structure
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
        if "}" in f[k]:
            structure[number_bracketr - 1][2] = k
            number_bracketr -= 1
            level -= 1
        if level == 1:
            number_bracketr = 0

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
    number_of_level = []
    for k in range(len(structure)):
        if structure[k][0] == "for":
            if structure[k][3] == 1:
                number_of_level += [k]
    if len(number_of_level) == 1:
        write_c_file("tensorize_files/" + name + ".c", structure[1][1], f, structure)
    else:
        structure1 = structure[:number_of_level[1]]
        structure2 = [structure[0]] + structure[number_of_level[1]:]

        write_c_file("tensorize_files/" + name + "1.c", structure[1][1], f, structure1)
        write_c_file("tensorize_files/" + name + "2.c", structure[1][1], f, structure2)

    # information for tensorize i.e. factor of tilling
    info_tensorize = {}


    if len(number_of_level)==1:
        info_tensorize[1] = {
            "factor_out_channels": factor("f", structure),
            "factor_xx": factor("x", structure),
            "factor_yy": factor("y", structure),
            "factor_in_channels": factor("c", structure)
        }
    else:
        info_tensorize[1] = {
            "height": factor("height", structure1),
            "factor_out_channels": factor("f", structure1),
            "factor_xx": factor("x", structure1),
            "factor_yy": factor("y", structure1),
            "factor_in_channels": factor("c", structure1),
        }
        info_tensorize[2] = {
            "height": factor("height", structure2),
            "factor_out_channels": factor("f", structure2),
            "factor_xx": factor("x", structure2),
            "factor_yy": factor("y", structure2),
            "factor_in_channels": factor("c", structure2)
        }



    return info_tensorize
