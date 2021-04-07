import os
import input_conv

archi = "avx2"
# archi = "avx512"

nb_runs = 2

# for key in input_conv.input_conv:
for key in ["MobilNet_1"]:
    if input_conv.input_conv[key][-1] == 1: # stride = 1
        os.system("python3.8 main.py " + key + " " + archi + " " + str(nb_runs))