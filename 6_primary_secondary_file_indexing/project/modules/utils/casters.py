def cast_numerical_elems_to_int(list):
    return [int(elem) if str(elem).isnumeric() else elem for elem in list]
