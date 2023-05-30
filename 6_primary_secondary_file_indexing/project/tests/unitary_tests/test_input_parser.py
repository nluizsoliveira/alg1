from project.modules.parsers.input_parser import parse_input

CASES_STRING = """ADD id='5' titulo='The Diary of a Young Girl' autor='Anne Frank'
ADD id='5' titulo='The Diary of a Young Girl' autor='Anne Frank'
SEARCH id='5'
REMOVE id='10'
REMOVE id='5'
SEARCH id='5'
ADD id='8' titulo='The Fault in Our Stars' autor='John Green'
ADD id='14' titulo='Looking for Alaska' autor='John Green'
SEARCH autor='John Green'
REMOVE autor='Anne Frank'
REMOVE autor='John Green'
SEARCH autor='John Green'
EXIT"""

cases = CASES_STRING.split('\n')

print(" ========== TEST INPUT PARSER ========= ")
for index, case in enumerate(cases):
    print(f'case {index}:')
    print('\tinput: ', case)
    print('\toutput:', parse_input(case))

