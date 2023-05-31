from project.modules.orchestrator import Orchestrator
from project.parsers.input_parser import parse_input

RECORDS_FILE_AND_INDEXES_FOLDER = 'outputs_folder/'
orchestrator = Orchestrator(RECORDS_FILE_AND_INDEXES_FOLDER)

operation = ''
while operation != 'EXIT':
    operation, *args = parse_input(input())
    orchestrator.call(operation, *args)








