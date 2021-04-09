import numpy as np
#Xeon [8 192, 262 144, 5 767 168],
#i7 [8 192, 65 536, 1 572 864],

convert = {
    "f": "axe_out_channels",
    "c": "axe_in_channels",
    "x": "axe_xx",
    "y": "axe_yy",
    "w": "axe_kernel_w",
    "h": "axe_kernel_h"
}

order = {
    "xeon": {},
    "i7": {}
}

order["xeon"] = {
    # "MobilNet-1":  { 'L1': ["y","f","c","w","h"],  'L2':["x","y","f"],             'L3':["y"],              'MEM':["x","y","f","c","w","h"]},
    # "MobilNet-2":  { 'L1': ["f","x","y"],          'L2':["w","h","c","f","y"],     'L3':["x","y"],          'MEM':["x","y","f","c","w","h"]},
    # "MobilNet-3":  { 'L1': ["f","x","y"],          'L2':["w","h","c","f","y"],     'L3':["x","y"],          'MEM':["x","y","f","c","w","h"]},
    # "MobilNet-4":  { 'L1': ["f","x","y"],          'L2':["w","h","c","f","y"],     'L3':["x","y"],          'MEM':["x","y","f","c","w","h"]},
    # "MobilNet-5":  { 'L1': ["f","x","y"],          'L2':["w","h","c","x","y"],     'L3':["f","c","x","y"],  'MEM':["x","y","f","c","w","h"]},
    # "MobilNet-6":  { 'L1': ["f","x","y"],          'L2':["w","h","c","f"],         'L3':["x","y","f","c"],  'MEM':["x","y","f","c","w","h"]},
    # "MobilNet-7":  { 'L1': ["f","x","y"],          'L2':["w","h","c"],             'L3':["f","c"],          'MEM':["x","y","f","c","w","h"]},
    # "MobilNet-8":  { 'L1': ["f","x","y"],          'L2':["w","h","c","x","y"],     'L3':["f","c"],          'MEM':["x","y","f","c","w","h"]},
    # "MobilNet-9":  { 'L1': ["c","f","x","y"],      'L2':["w","h","c"],             'L3':["f","c"],          'MEM':["w","h","c","f","x","y"]},
    # "ResNet18-1":  { 'L1': ["y","f","c","w","h"],  'L2':["x","y","f"],             'L3':["y"],              'MEM':["x","y","f","c","w","h"]},
    # "ResNet18-2":  { 'L1': ["f","x","y"],          'L2':["w","h","c","f","x","y"], 'L3':["x"],              'MEM':["x","y","f","c","w","h"]},
    # "ResNet18-3":  { 'L1': ["x","y","f","c"],      'L2':["x","y"],                 'L3':["x","y"],          'MEM':["x","y","f","c","w","h"]},
    # "ResNet18-4":  { 'L1': ["f","x","y"],          'L2':["w","h","c","f","y"],     'L3':["x","y"],          'MEM':["x","y","f","c","w","h"]},
    # "ResNet18-5":  { 'L1': ["f","c"],              'L2':["y","f"],                 'L3':["x"],              'MEM':["x","y","f","c","w","h"]},
    # "ResNet18-6":  { 'L1': ["f","x","y"],          'L2':["w","h","c","f","y"],     'L3':["x","y"],          'MEM':["x","y","f","c","w","h"]},
    # "ResNet18-7":  { 'L1': ["f","x","y"],          'L2':["w","h","c","f"],         'L3':["x","y","f","c"],  'MEM':["x","y","f","c","w","h"]},
    # "ResNet18-8":  { 'L1': ["f","x","y"],          'L2':["w","h","c","f"],         'L3':["x","y","f"],      'MEM':["x","y","f","c","w","h"]},
    # "ResNet18-9":  { 'L1': ["f","x","y"],          'L2':["w","h","c","f"],         'L3':["f"],              'MEM':["x","y","f","c","w","h"]},
    # "ResNet18-10": { 'L1':["f","x","y"],           'L2':["w","h","c","x","y"],     'L3':["f","c"],          'MEM':["x","y","f","c","w","h"]},
    # "ResNet18-11": { 'L1':["f","x","y"],           'L2':["c","f"],                 'L3':["y"],              'MEM':["x","y","f","c","w","h"]},
    # "ResNet18-12": { 'L1':["c","f","x","y"],       'L2':["w","h","c"],             'L3':["f","c"],          'MEM':["x","y","f","c","w","h"]},
    # "Yolo9000-0":  { 'L1': ["y","f","c","w","h"],  'L2':["x"],                     'L3':["x","y"],          'MEM':["y","x","f","c","w","h"]},
    # "Yolo9000-2":  { 'L1': ["c","x","y"],          'L2':["w","h","f","y"],         'L3':["x","y"],          'MEM':["y","x","f","c","w","h"]},
    # "Yolo9000-4":  { 'L1': ["f","x","y"],          'L2':["w","h","c","f","y"],     'L3':["x","y"],          'MEM':["x","y","f","c","w","h"]},
    # "Yolo9000-5":  { 'L1': ["f","c"],              'L2':["x","y","f","c"],         'L3':["x","y"],          'MEM':["x","y","f","c","w","h"]},
    # "Yolo9000-8":  { 'L1': ["f","x","y"],          'L2':["w","h","c","f"],         'L3':["x","y","f"],      'MEM':["x","y","f","c","w","h"]},
    # "Yolo9000-9":  { 'L1': ["f","x","y"],          'L2':["c","f","x","y"],         'L3':["x","y"],          'MEM':["x","y","f","c","w","h"]},
    # "Yolo9000-12": { 'L1':["f","x","y"],           'L2':["w","h","c","x","y"],     'L3':["f","c","x","y"],  'MEM':["x","y","f","c","w","h"]},
    # "Yolo9000-13": { 'L1':["f","x","y"],           'L2':["c","f","x","y"],         'L3':["x","y"],          'MEM':["x","y","f","c","w","h"]},
    # "Yolo9000-18": { 'L1':["f","x","y"],           'L2':["w","h","c","x","y"],     'L3':["f","c"],          'MEM':["x","y","f","c","w","h"]},
    # "Yolo9000-19": { 'L1':["f","x","y"],           'L2':["c","f"],                 'L3':["x","y","f","c"],  'MEM':["x","y","f","c","w","h"]},
    # "Yolo9000-23": { 'L1':["f","x","y"],           'L2':["c","x","y"],             'L3':["f","c"],          'MEM':["x","y","f","c","w","h"]}
}

order["i7"] = {
    "MobilNet-1":  { 'CPU':['f','y'],  'L1':['c','w','h'],  'L2':['x','y','c'],  'MEM':['y','x','f','c','w','h']},
    # "MobilNet-2":  { 'L1':["f","x","y"],              'L2':["w","h","c"],      'L3':["x","y"],          'MEM':["w","h","c","f","x","y"]},
    # "MobilNet-3":  { 'L1':["f","x","y"],              'L2':["w","h","c"],      'L3':["x","y","f","c"],  'MEM':["x","y","f","c","w","h"]},
    # "MobilNet-4":  { 'L1':["f","x","y"],              'L2':["w","h","c"],      'L3':["x","y","f","c"],  'MEM':["w","h","c","f","x","y"]},
    # "MobilNet-5":  { 'L1':["f","x","y"],              'L2':["w","h","c"],      'L3':["f","c","x","y"],  'MEM':["x","y","f","c","w","h"]},
    # "MobilNet-6":  { 'L1':["f","x","y"],              'L2':["w","h","c"],      'L3':["x","y","f","c"],  'MEM':["w","h","f","c","x","y"]},
    # "MobilNet-7":  { 'L1':["f","x","y"],              'L2':["w","h","c"],      'L3':["f","c"],          'MEM':["w","h","c","f","x","y"]},
    # "MobilNet-8":  { 'L1':["f","x","y"],              'L2':["w","h","c"],      'L3':["f","c","x","y"],  'MEM':["w","h","c","f","x","y"]},
    # "MobilNet-9":  { 'L1':["f","c","x","y"],          'L2':["w","h","f"],      'L3':["c","f"],          'MEM':["w","h","f","c","x","y"]},
    # "ResNet18-1":  { 'L1':["c","x","y"],              'L2':["w","h","f","y"],  'L3':["x","y"],          'MEM':["y","x","f","c","w","h"]},
    # "ResNet18-2":  { 'L1':["f","x","y"],              'L2':["w","h","c","f"],  'L3':["x","y","f"],      'MEM':["x","y","f","c","w","h"]},
    # "ResNet18-3":  { 'L1':["x","y","f","c"],          'L2':["x","y"],          'L3':["x","y"],          'MEM':["x","y","f","c","w","h"]},
    # "ResNet18-4":  { 'L1':["f","x","y"],              'L2':["w","h","c"],      'L3':["x","y","f","c"],  'MEM':["x","y","f","c","w","h"]},
    # "ResNet18-5":  { 'L1':["f","c"],                  'L2':["y","f"],          'L3':["x"],              'MEM':["x","y","f","c","w","h"]},
    # "ResNet18-6":  { 'L1':["f","x","y"],              'L2':["w","h","c"],      'L3':["f","c","x","y"],  'MEM':["x","y","f","c","w","h"]},
    # "ResNet18-7":  { 'L1':["f","x","y"],              'L2':["w","h","c"],      'L3':["x","y","f","c"],  'MEM':["x","y","f","c","w","h"]},
    # "ResNet18-8":  { 'L1':["f","x","y"],              'L2':["w","h","c"],      'L3':["f","c","x","y"],  'MEM':["x","y","f","c","w","h"]},
    # "ResNet18-9":  { 'L1':["f","x","y"],              'L2':["w","h","c"],      'L3':["f","c"],          'MEM':["x","y","f","c","w","h"]},
    # "ResNet18-10": { 'L1':["f","x","y"],              'L2':["w","h","c"],      'L3':["f","c","x","y"],  'MEM':["w","h","c","f","x","y"]},
    # "ResNet18-11": { 'L1':["f","c"],                  'L2':["x","y","c"],      'L3':["f","c"],          'MEM':["y","x","f","c","w","h"]},
    # "ResNet18-12": { 'L1':["f","c","x","y"],          'L2':["w","h","f"],      'L3':["c","f"],          'MEM':["w","h","f","c","x","y"]},
    # "Yolo9000-0":  { 'L1':["x","y","f","c","w","h"],  'L2':["x"],              'L3':["x","y"],          'MEM':["y","x","f","c","w","h"]},
    # "Yolo9000-2":  { 'L1':["c","x","y"],              'L2':["w","h","f","y"],  'L3':["x","y"],          'MEM':["y","x","f","c","w","h"]},
    # "Yolo9000-4":  { 'L1':["f","x","y"],              'L2':["w","h","c","f"],  'L3':["x","y"],          'MEM':["w","h","f","c","x","y"]},
    # "Yolo9000-5":  { 'L1':["f","c"],                  'L2':["x","y","f","c"],  'L3':["x","y"],          'MEM':["x","y","f","c","w","h"]},
    # "Yolo9000-8":  { 'L1':["f","x","y"],              'L2':["w","h","c"],      'L3':["x","y","f","c"],  'MEM':["w","h","f","c","x","y"]},
    # "Yolo9000-9":  { 'L1':["f","x","y"],              'L2':["c","f"],          'L3':["x","y"],          'MEM':["x","y","f","c","w","h"]},
    # "Yolo9000-12": { 'L1':["f","x","y"],              'L2':["w","h","c"],      'L3':["f","c","x","y"],  'MEM':["w","h","c","f","x","y"]},
    # "Yolo9000-13": { 'L1':["f","x","y"],              'L2':["c"],              'L3':["x","y","f","c"],  'MEM':["x","y","f","c","w","h"]},
    # "Yolo9000-18": { 'L1':["f","x","y"],              'L2':["w","h","c"],      'L3':["f","c"],          'MEM':["w","h","c","f","x","y"]},
    # "Yolo9000-19": { 'L1':["f","x","y"],              'L2':["c"],              'L3':["f","c","x","y"],  'MEM':["x","y","f","c","w","h"]},
    # "Yolo9000-23": { 'L1':["f","x","y"],              'L2':["c"],              'L3':["f","c"],          'MEM':["x","y","f","c","w","h"]}

}

def find_fuse(l):
    fuse = []
    fuse_int = []
    for k in range(len(l)):
        if "axe_kernel" not in l[k] and "axe_in_channels" not in l[k]:
            fuse_int +=[l[k]]
        else:
            if len(fuse_int) != 0:
                fuse += [fuse_int]
    if len(fuse) == 0:
        return fuse_int
    else:
        maxi = 0
        id_max = 0
        for k in range(len(fuse)):
            if len(fuse) > maxi:
                maxi = len(fuse)
                id_max = k
        return fuse[id_max]


def reorder(name_conv, name_archi):
    result = ""
    reorder = order[name_archi][name_conv]
    lorder = []
    lorder += order[name_archi][name_conv]["CPU"]
    beginl1 = len(order)
    lorder += order[name_archi][name_conv]["L1"]
    beginl2 = len(lorder)
    lorder += order[name_archi][name_conv]["L2"]
    endl2 = len(lorder)
    lorder += order[name_archi][name_conv]["MEM"]
    lorder = list(map(lambda x: convert[x], lorder))
    counter = {
        "axe_out_channels": 0,
        "axe_in_channels" : 0,
        "axe_xx"          : 0,
        "axe_yy"          : 0,
        "axe_kernel_w"    : 0,
        "axe_kernel_h"    : 0
    }
    for k in range(len(lorder)):
        name = lorder[k]
        lorder[k] = lorder[k] + "_" + str(counter[name])
        counter[name] += 1

    cpu = lorder[:beginl1]
    l1 = lorder[beginl1:beginl2]
    l2 = lorder[beginl2:endl2]
    mem = lorder[endl2:]
    
    lorder.reverse()
    cpu.reverse()
    l1.reverse()
    l2.reverse()
    mem.reverse()

    fuse = find_fuse(mem)

    return lorder, cpu, l1, l2, fuse

