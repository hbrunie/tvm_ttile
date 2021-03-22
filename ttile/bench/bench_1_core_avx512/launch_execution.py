import os
import input_conv

import time

for key in input_conv.input_conv:
    t1 = time.time()
    os.system("python3 conv_NCHW.py " + key)
    t2 = time.time()
    t = t2 - t1
    f = open("temps_recherche.txt", "a")
    f.write(str(t) + "\n")
    f.close()
