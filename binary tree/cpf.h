#ifndef _cpf_
#define _cpf_	

static const char PARSE_CPF_TEST_CASES[5][15] = {
    "186.161.140-41",
    "834.772.252-87",
    "977.535.257-60",
    "150.664.433-39",
    "550.980.261-80"
};

static const unsigned long long int PARSE_CPF_EXPECTED_OUTPUTS[5] = {
    18616114041,
    83477225287,
    97753525760,
    15066443339,
    55098026180
};

unsigned long long int parse_cpf(const char* cpf_with_special_characters);
void test_parse_cpf();
void print_cpf(long long int cpf);
#endif