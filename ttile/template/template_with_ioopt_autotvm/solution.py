import input_conv
import input_sol

# sol = {'Tw_0': 1, 'Th_0': 1, 'Tc_0': 1, 'Tf_0': 32, 'Tx_0': 14, 'Ty_0': 16, 'Tw_1': 3, 'Th_1': 3, 'Tc_1': 128, 'Tf_1': 128, 'Tx_1': 14, 'Ty_1': 27, 'Tx_2': 56, 'Ty_2': 56, 'Tf_2': 128, 'Tc_2': 128, 'Tw_2': 3, 'Th_2': 3}

def solution(name_input, name_archi):

    sol = input_sol.sol[name_archi][name_input]

    dic = {
        "w": [0],
        "h": [0],
        "f": [0],
        "c": [0],
        "x": [0],
        "y": [0]
    }

    size_input = input_conv.input_conv

    #K*C*H*W*R*S
    equi = {
        "f":0,
        "c":1,
        "x":2,
        "y":3,
        "h":4,
        "w":5
    }

    for key in sol:
        variable = key[1]
        id_variable = int(key[3])
        tile = sol[key]
        if dic[variable][0] < id_variable + 1 and tile != 1 and tile != size_input[name_input][equi[variable]] and tile!= dic[variable][-1]:
            dic[variable][0] += 1
            dic[variable] += [tile]
    return(dic)

