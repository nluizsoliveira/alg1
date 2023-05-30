from project.indexing_orchestrator import Orchestrator
from project.parsers.input_parser import parse_input

output_path = 'output_files/'
orchestrator = Orchestrator(output_path)

OPERATIONS = {
    'ADD': orchestrator.add,
    'SEARCH': orchestrator.search,
    'REMOVE': orchestrator.remove,
    'EXIT': orchestrator.exit,
}

cases_string = """ADD id='5' titulo='The Diary of a Young Girl' autor='Anne Frank'
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

input_cases = cases_string.split('\n')

for input in input_cases:
    operation, *args = parse_input(input)
    OPERATIONS[operation](*args)