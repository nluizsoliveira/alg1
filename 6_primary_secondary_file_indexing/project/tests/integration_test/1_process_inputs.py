from os import listdir
from project.modules.orchestrator import Orchestrator
from project.modules.parsers.input_parser import parse_input
from project.tests.integration_test import INPUTS_PATH, OUTPUT_FILES_PATH

inputs_filenames = listdir(INPUTS_PATH)
for index, input_filename in enumerate(inputs_filenames, start=1):
    orchestrator = Orchestrator(f'{OUTPUT_FILES_PATH}{index}/')

    input_file = open(INPUTS_PATH + input_filename)
    raw_inputs = input_file.read()

    for input in raw_inputs.strip().split('\n'):
        operation, *args = parse_input(input)
        orchestrator.call(operation, *args)

    print('@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@@')

    input_file.close()