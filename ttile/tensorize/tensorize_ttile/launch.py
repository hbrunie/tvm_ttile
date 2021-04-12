import os
import input_conv

# archi = "avx2"
archi = "avx512"

nb_runs = 200

for key in input_conv.input_conv:
    os.system("python3 main.py " + key + " " + archi + " " + str(nb_runs))
