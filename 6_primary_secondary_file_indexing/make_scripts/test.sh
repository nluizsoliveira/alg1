#!/bin/bash

test_cases_folder="test_cases/"

correct_cases=0
total_cases=0

echo "========== Test main.py ============"

for input_file in "$test_cases_folder"/*.in;
do
    ((total_cases++))
    if [[ -f "$input_file" ]];
    then
        mkdir "project/output_files/"
        case_number=$(basename "$input_file" .in)
        expected_output_file="$test_cases_folder/$case_number.out"
        returned_output_file="$test_cases_folder/$case_number.returned"

        python3 project/main.py < "$input_file" > "$returned_output_file"

        if cmp -s "$returned_output_file" "$expected_output_file";
        then
            echo "    case $case_number: (V) Passed"
            ((correct_cases++))
        else
            echo "    case $case_number: (X) Failed"
        fi
        rm -rf "project/output_files/"
    else
        echo "no .in file in directory"
    fi
done

echo "=============== $correct_cases/$total_cases ==============="

