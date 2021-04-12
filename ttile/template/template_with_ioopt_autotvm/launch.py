import generate_template
import reorder


import sys
sys.path.insert(1, 'template/')

# name_input = "ResNet18-9"

target = "llvm -mcpu=core-avx2"
archi = "i7"

for name_input in ["MobilNet-1"]:#  ,"MobilNet-2"  ,"MobilNet-3"  ,"MobilNet-4"  ,"MobilNet-5"  ,"MobilNet-6"  ,"MobilNet-7"  ,"MobilNet-8"  ,"MobilNet-9"  ,"ResNet18-1"  ,"ResNet18-2"  ,"ResNet18-3"  ,"ResNet18-4"  ,"ResNet18-5"  ,"ResNet18-6"  ,"ResNet18-7"  ,"ResNet18-8"  ,"ResNet18-9"  ,"ResNet18-10" ,"ResNet18-11" ,"ResNet18-12" ,"Yolo9000-0"  ,"Yolo9000-2"  ,"Yolo9000-4"  ,"Yolo9000-5"  ,"Yolo9000-8"  ,"Yolo9000-9"  ,"Yolo9000-12" ,"Yolo9000-13" ,"Yolo9000-18" ,"Yolo9000-19" ,"Yolo9000-23"]:
# for name_input in ["MobilNet-9"]:
    nb_configuration = reorder.number_of_configuration(name_input, archi)
    # for id_ in range(nb_configuration):
    for id_ in range(1):
        generate_template.generate_template(name_input, id_, target, archi)
        generate_template.generate_apply_best(name_input, id_, target, archi)
        template_name = name_input.replace("-", "_")
        exec("import template_%s" % (template_name))
        exec("template_%s.evaluate()" % (template_name))

