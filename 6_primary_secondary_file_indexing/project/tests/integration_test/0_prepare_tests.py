from os import path, listdir, mkdir, remove
from shutil import rmtree
from project.tests.integration_test import INPUTS_PATH, EXPECTED_OUTPUTS_PATH, OUTPUT_FILES_PATH, DUMPED_STDOUT_PATH

def clean_tests():
    if path.isdir(OUTPUT_FILES_PATH):
        rmtree(OUTPUT_FILES_PATH)
    
    if path.isdir(DUMPED_STDOUT_PATH):
        rmtree(DUMPED_STDOUT_PATH)

def check_IO_folders():
    inputs_folder = path.isdir(INPUTS_PATH)
    expected_outputs_folder = path.isdir(EXPECTED_OUTPUTS_PATH)
    if not inputs_folder or not expected_outputs_folder:
        print('ERROR: no inputs/ or expected_outputs/ folder')
        print(f'\t inputs/: {inputs_folder}, expected_outputs/: {expected_outputs_folder}')
        return None
    else:
        qtd_inputs = len(listdir(INPUTS_PATH))
        qtd_outputs = len(listdir(EXPECTED_OUTPUTS_PATH))

        if qtd_inputs == 0 or qtd_outputs == 0:
            print('ERROR: inputs/ or expected_outputs/ are empty')
            print(f'\tqtd_inputs: {qtd_inputs}, qtd_outputs{qtd_outputs}')
            return None
        elif qtd_inputs != qtd_outputs:
            print('ERROR: inputs quantity != outputs quantity')
            print(f'\tqtd_inputs: {qtd_inputs}, qtd_outputs{qtd_outputs}')
            return None
        
    return qtd_inputs


def prepare_folder_structure():
    mkdir(OUTPUT_FILES_PATH)
    mkdir(DUMPED_STDOUT_PATH)
    for i in range(1, qtd_inputs+1):
        mkdir(OUTPUT_FILES_PATH + str(i))


qtd_inputs = check_IO_folders()
if qtd_inputs:
    clean_tests()
    prepare_folder_structure()
    

