#!/usr/bin/env python3
import os
import input_conv
import time
import argcomplete, argparse
import main
from parser import ParEnum


parser = argparse.ArgumentParser(description='Launching python3 main.py')
parser.add_argument('namecpu', type=str, help='Change the cpu name for the dump directory name. (default is E5)', default="E5")
parser.add_argument('--avx', type=str, help='Which version of AVX (default is avx2).', choices=("avx2","avx512"), default="avx2")
parser.add_argument('--nbthreads', type=int, help='How many threads to launch with (default is 1).', default=1)
parser.add_argument('--nbconfigurations', type=int, help='How many configurations to test with (default is 200).', default=200)
parser.add_argument('--architecture', type=str, help='Which architecture (default is broadwell), they corresponds to the ones in matmul_bench/ml_utils/python_frontend/python_frontend.ml.', default="broadwell")
parser.add_argument('--debug', help="More verbose", action='store_true', default=False)
parser.add_argument('--method', type=str, help='Which method (default is random).', choices=("random","metric"), default="random")
argcomplete.autocomplete(parser)
args = parser.parse_args()


NUM_THREAD = args.nbthreads
avx = args.avx
name_cpu = args.namecpu
nb_configuration = args.nbconfigurations
architecture = args.architecture
method = args.method

lpar_methods = [ParEnum.LARGEST_SLICE, ParEnum.REDUCTION_INNER, ParEnum.REDUCTION_OUTER]

for convolution in input_conv.input_conv:
    main.conv2d(convolution, architecture, avx, nb_configuration,
            name_cpu, NUM_THREAD, lpar_methods, method)
