# Function for creating an enum type.
# See here https://www.pythoncentral.io/how-to-implement-an-enum-in-python/
def enum(*args):
    # populating a dict with dummy values (0, 1, 2...)
    args_dict = dict(zip(args, range(len(args))))
    # type(name, base class, dict) dynamically creates
    # a class with attributes found in dict 
    return type('Enum', (), args_dict)
