import os
import numpy as np
import input_conv
from ttilepy import *
from utils import enum

class cd:
    """Context manager for changing the current working directory"""
    def __init__(self, newPath):
        self.newPath = os.path.expanduser(newPath)

    def __enter__(self):
        self.savedPath = os.getcwd()
        os.chdir(self.newPath)

    def __exit__(self, etype, value, traceback):
        os.chdir(self.savedPath)


convert_axes = {
    "F": "axe_out_channels",
    "C": "axe_in_channels",
    "X": "axe_xx",
    "Y": "axe_yy",
    "W": "axe_w",
    "H": "axe_h",
}

def sort_reduction_up(out_tensorize):
    """
    Sort the array out_tensorize with all reduction axes first
    """
    out_tensorize_ = []
    out_tensorize_rec = []
    for k in range(len(out_tensorize)):
        if out_tensorize[k][0] == "C" or out_tensorize[k][0] == "H" or out_tensorize[k][0] == "W":
            out_tensorize_rec.append(out_tensorize[k])
        else:
            out_tensorize_.append(out_tensorize[k])
    for k in range(len(out_tensorize_)):
        out_tensorize_rec.append(out_tensorize_[k])
    return out_tensorize_rec

def sort_reduction_down(out_tensorize):
    """
    Sort the array out_tensorize with all reduction axes at the end
    """
    out_tensorize_ = []
    out_tensorize_rec = []
    for k in range(len(out_tensorize)):
        if out_tensorize[k][0] == "C" or out_tensorize[k][0] == "H" or out_tensorize[k][0] == "W":
            out_tensorize_rec.append(out_tensorize[k])
        else:
            out_tensorize_.append(out_tensorize[k])
    for k in range(len(out_tensorize_rec)):
        out_tensorize_.append(out_tensorize_rec[k])
    return out_tensorize_




def fuse_all(out_tensorize, suffix):
    """
    Function which choose all axes to fuse for parallelization and give the size of this fuse loop
    """
    fuse_ = []
    size_int = 1

    counter = {
        "F":0,
        "C":0,
        "X":0,
        "Y":0,
        "H":0,
        "W":0
    }

    for k, element in enumerate(out_tensorize):
        fuse_ += [convert_axes[element[0]] + suffix + "_" + str(counter[element[0]])]
        counter[element[0]] += 1
        size_int *= element[1]
    return fuse_, size_int


def fuse_first_loop(out_tensorize, number, suffix):
    fuse_ = []
    size_int = 1
    counter = {
        "F":0,
        "C":0,
        "X":0,
        "Y":0,
        "H":0,
        "W":0
    }
    for k in range(number):
        element = out_tensorize[k]
        fuse_ += [convert_axes[element[0]] + suffix + "_" + str(counter[element[0]])]
        counter[element[0]] += 1
        size_int *= element[1]
    return fuse_, size_int


def fuse(out_tensorize, suffix, NUM_THREAD):
    """
    Function which choose the axes to fuse for parallelization and give the size of this fuse loop
    """
    fuse_ = []
    fuse_int = []
    size_int = 1

    counter = {
        "F":0,
        "C":0,
        "X":0,
        "Y":0,
        "H":0,
        "W":0
    }

    for k, element in enumerate(out_tensorize):
        if element[0] == "C" or element[0] == "H" or element[0] == "W":
            fuse_ += [[fuse_int, size_int]]
            fuse_int = []
            size_int = 1
        else:
            fuse_int += [convert_axes[element[0]] + suffix + "_" + str(counter[element[0]])]
            counter[element[0]] += 1
            size_int *= element[1]
    fuse_ += [[fuse_int, size_int]]
    id_max = 0
    size_max = 0

    id_greater_than_threads = []

    for i in range(len(fuse_)):
        if size_max < fuse_[i][1]:
            id_max = i
            size_max = fuse_[i][1]
        if fuse_[i][1] >= NUM_THREAD:
            print(fuse_[i][1] , NUM_THREAD)
            id_greater_than_threads += [i]
    if len(id_greater_than_threads) != 0:
        id_ = id_greater_than_threads[0]
        return fuse_[id_][0], fuse_[id_][1]
    else:
        return fuse_[id_max][0], fuse_[id_max][1]


# Here we define an enum type with all parallelization methods (cleaner than calling
# them by id)
ParEnum = enum('LARGEST_SLICE', 'REDUCTION_OUTER', 'REDUCTION_INNER',
        'FUSE_ALL', 'FUSE_OUTER_ONE_LOOP', 'FUSE_OUTER_TWO_LOOPS')

all_methods = [ParEnum.LARGEST_SLICE, ParEnum.REDUCTION_OUTER, ParEnum.REDUCTION_INNER,
        ParEnum.FUSE_ALL, ParEnum.FUSE_OUTER_ONE_LOOP, ParEnum.FUSE_OUTER_TWO_LOOPS]

def schedule(out_tensorize, in_tensorize, suffix):
    """
    Give the schedule of the convolution
    """
    counter = {
        "F":0,
        "C":0,
        "X":0,
        "Y":0,
        "H":0,
        "W":0
    }
    l = out_tensorize + in_tensorize
    schedule_ = []
    for k, element in enumerate(l):
        schedule_.append(convert_axes[element[0]] + suffix + "_" + str(counter[element[0]]))
        counter[element[0]] += 1
    return schedule_

def schedule_up(out_tensorize, in_tensorize, suffix):
    """
    Give the schedule of the convolution
    """
    counter = {
        "F":0,
        "C":0,
        "X":0,
        "Y":0,
        "H":0,
        "W":0
    }
    out_tensorize = sort_reduction_up(out_tensorize)
    l = out_tensorize + in_tensorize
    schedule_ = []
    for k, element in enumerate(l):
        schedule_.append(convert_axes[element[0]] + suffix + "_" + str(counter[element[0]]))
        counter[element[0]] += 1
    return schedule_

def schedule_down(out_tensorize, in_tensorize, suffix):
    """
    Give the schedule of the convolution
    """
    counter = {
        "F":0,
        "C":0,
        "X":0,
        "Y":0,
        "H":0,
        "W":0
    }
    out_tensorize = sort_reduction_down(out_tensorize)
    l = out_tensorize + in_tensorize
    schedule_ = []
    for k, element in enumerate(l):
        schedule_.append(convert_axes[element[0]] + suffix + "_" + str(counter[element[0]]))
        counter[element[0]] += 1
    return schedule_

def factor(variable, out_tensorize, in_tensorize, size):
    """
    Give the factor of split for each variable
    """
    l = out_tensorize + in_tensorize
    count = 0
    factor_ = []
    # keep only factors corresponding to 'variable'
    fact_on_variable = list(filter(lambda tup: tup[0] == variable, l))
    # don't mutate function argument (this is not a huge problem but I don't like this much)
    size_ = size
    results = []
    # We don't care about the last element
    for (_dim, f) in fact_on_variable[:-1]:
        size_ //= f
        results.append(size_)
    return results

def find_size_tensorize(variable, in_tensorize):
    for element in in_tensorize:
        if element[0] == variable:
            if variable == "Y" or variable == "X":
                return element[1]
            else:
                return element[1]
    return -1

def check(out_tensorize):
    set_ = set()
    for k in range(len(out_tensorize)):
        variable, iteration = out_tensorize[k]
        set_.add(variable)
    if "X" not in set_:
        out_tensorize.append(("X", 1))
    if "C" not in set_:
        out_tensorize.append(("C", 1))
    if "F" not in set_:
        out_tensorize.append(("F", 1))
    return out_tensorize

def axe_fuse_from_par_method(par_method, out_tensorize, suffix, NUM_THREAD):
    if par_method == ParEnum.LARGEST_SLICE:
        return fuse(out_tensorize, suffix, NUM_THREAD)
    elif par_method == ParEnum.REDUCTION_OUTER:
        return fuse(sort_reduction_up(out_tensorize), suffix, NUM_THREAD)
    elif par_method == ParEnum.REDUCTION_INNER:
        return fuse(sort_reduction_down(out_tensorize), suffix, NUM_THREAD)
    elif par_method == ParEnum.FUSE_ALL:
        return fuse_all(out_tensorize, suffix)
    elif par_method == ParEnum.FUSE_OUTER_ONE_LOOP:
        return fuse_first_loop(out_tensorize, 1, suffix)
    else: # par_method == ParEnum.FUSE_OUTER_TWO_LOOPS:
        return fuse_first_loop(out_tensorize, 2, suffix)

def lschedule_from_par_method(par_method, out_tensorize, in_tensorize, suffix):
    if par_method == ParEnum.REDUCTION_OUTER:
        return schedule_up(out_tensorize, in_tensorize, suffix)
    elif par_method == ParEnum.REDUCTION_INNER:
        return schedule_down(out_tensorize, in_tensorize, suffix)
    else:
        return schedule(out_tensorize, in_tensorize, suffix)

def build_info_tensorize(width, height, kw, kh, out_channels, in_channels, stride,
        par_method, out_tensorize, in_tensorize, file_, suffix, NUM_THREAD):
    axe_fuse, size_axe_fuse = axe_fuse_from_par_method(par_method, out_tensorize, suffix, NUM_THREAD)
    schedule_ = schedule(out_tensorize, in_tensorize, suffix)
    lschedule = lschedule_from_par_method(par_method, out_tensorize, in_tensorize, suffix)
    return {
            "height"               : height,
            "factor_out_channels"  : factor("F", out_tensorize, in_tensorize, out_channels),
            "factor_xx"            : factor("X", out_tensorize, in_tensorize, width // stride),
            "factor_yy"            : factor("Y", out_tensorize, in_tensorize, height),
            "factor_h"             : factor("H", out_tensorize, in_tensorize, kh),
            "factor_w"             : factor("W", out_tensorize, in_tensorize, kw),
            "factor_in_channels"   : factor("C", out_tensorize, in_tensorize, in_channels),
            "order"                : lschedule,
            "nb_loop_no_tensorize" : len(out_tensorize),
            "axe_to_tensorize"     : schedule_[len(out_tensorize)],
            "h_t"                  : find_size_tensorize("H", in_tensorize),
            "w_t"                  : find_size_tensorize("W", in_tensorize),
            "f_t"                  : find_size_tensorize("F", in_tensorize),
            "c_t"                  : find_size_tensorize("C", in_tensorize),
            "x_t"                  : find_size_tensorize("X", in_tensorize),
            "y_t"                  : find_size_tensorize("Y", in_tensorize),
            "fuse"                 : axe_fuse,
            "size_axe_fuse"        : size_axe_fuse,
            "schema"               : out_tensorize + in_tensorize,
            "file"                 : file_,
            }

def build_dict(out_channels, in_channels, height, width, kh, kw, stride,scheme, par_methods, NUM_THREAD):
    out_tensorize1, in_tensorize1, height1, file_1 = scheme[0]
    out_tensorize1 = check(out_tensorize1)
    out_tensorize1.reverse()
    in_tensorize1.reverse()
    info_tensorize = {}
    for method in par_methods:
        info_tensorize[method] = {}
        info_tensorize[method][1] = {}
    if len(scheme) > 1:
        lambda_ = True
        out_tensorize2, in_tensorize2, height2, file_2 = scheme[1]

        out_tensorize2 = check(out_tensorize2)
        out_tensorize2.reverse()
        in_tensorize2.reverse()
        for method in par_methods:
            info_tensorize[method][2] = {}
    else:
        lambda_ = False

    if lambda_:
        file_1 = file_1.replace("gen_conv", "gen_conv1")
        file_2 = file_2.replace("gen_conv", "gen_conv2")

    for method in par_methods:
        info1 = build_info_tensorize(width, height1, kw, kh, out_channels, in_channels, stride,
                method, out_tensorize1, in_tensorize1, file_1, "1", NUM_THREAD)
        info_tensorize[method][1] = info1

        if lambda_:
            info2 = build_info_tensorize(width, height2, kw, kh, out_channels, in_channels, stride,
                    method, out_tensorize2, in_tensorize2, file_2, "2", NUM_THREAD)
            info_tensorize[method][2] = info2
    return info_tensorize

def parser(name_conv, archi, nb_conf,  PATH_MATMUL, par_methods, method_parser, NUM_THREAD):

    """
    Parse the result of matmul_bench and gives one dictionnary with all information to main.py
    """

    out_channels, in_channels, height, width, kh, kw, stride, _ = input_conv.input_conv[name_conv]

    with cd(PATH_MATMUL):
        lschemes = gen_schemes(archi, method_parser, nb_conf, out_channels, in_channels, height // stride, width // stride, kh, kw, stride)
    return list(map(lambda scheme: build_dict(out_channels, in_channels, height, width, kh, kw, stride, scheme, par_methods, NUM_THREAD), lschemes))
