from project.modules.orchestrator import Orchestrator
from project.modules.utils.parsers import parse_input

RECORDS_FILE_AND_INDEXES_FOLDER = 'project/output_files/'

orchestrator = Orchestrator(
    folder = RECORDS_FILE_AND_INDEXES_FOLDER,
    debug = False, 
)

operation = ''
while operation != 'EXIT':
    operation, *args = parse_input(input())
    orchestrator.call(operation, *args)








