#!/bin/bash

test_cases_folder="project/tests/integration_test/test_cases"

correct_cases=0
total_cases=0

echo "========== Test main.py ============"
for input_file in "$test_cases_folder"/*.in;
do
    rm -rf "project/output_files/"
    mkdir "project/output_files/"

    total_cases=$((total_cases + 1))
    case_number=$(basename "$input_file" .in)
    expected_output_file="$test_cases_folder/$case_number.out"
    returned_output_file="$test_cases_folder/$case_number.returned"

    python3 main.py < "$input_file" > "$returned_output_file"

    if cmp -s "$returned_output_file" "$expected_output_file";
    then
        echo "    case $case_number: (V) Passed"
        correct_cases=$((correct_cases + 1))
    else
        echo "    case $case_number: (X) Failed"
    fi
done

echo "=============== $correct_cases/$total_cases ==============="

