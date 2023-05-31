from project.modules.orchestrator import Orchestrator
from project.modules.parsers.input_parser import parse_input


INPUTS_PATHS = ['inputs/1.in', 
                'inputs/2.in', 
                'inputs/3.in', 
                'inputs/4.in', 
                'inputs/5.in', 
                'inputs/6.in']

OUTPUTS_FILES_FOLDER = 'output_files/'


for index, input_path in enumerate(INPUTS_PATHS, start=1):
    orchestrator = Orchestrator(f'{OUTPUTS_FILES_FOLDER}{index}/')

    input_file = open(input_path)
    raw_inputs = input_file.read()

    for input in raw_inputs.strip().split('\n'):
        operation, *args = parse_input(input)
        orchestrator.call(operation, *args)

    print('@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@')

    input_file.close()