
def divide(inp_list: list, div_list: list) -> list:
    div_num = div_list[-1]
    res = [inp_list[0]]

    for k, inp in enumerate(inp_list[1:]):
        res.append(inp - res[k] * div_num)

    return res


if __name__ == "__main__":
    inp = [2, -3, -5, -12]
    div = [1, -3]

    print(divide(inp, div))