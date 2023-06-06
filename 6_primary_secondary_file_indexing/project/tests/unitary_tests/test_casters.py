from project.modules.utils.casters import cast_numerical_elems_to_int


list = [1, '1', 1.7, '1.7', 'abc']
touple = (1, '1', 1.7, '1.7', 'abc')
print('input', list)
print('input', touple)
casted_list = cast_numerical_elems_to_int(list)
casted_touple = cast_numerical_elems_to_int(touple)

print(casted_list)
print(casted_touple)

for elem in casted_list:
    print(elem, type(elem), end=' ')
print()
for elem in casted_touple:
    print(elem, type(elem), end=' ')