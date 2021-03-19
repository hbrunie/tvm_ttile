import os
import input_conv

for key in input_conv.input_conv:
    os.system("python3 conv_NCHW.py " + key)