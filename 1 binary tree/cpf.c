#include<stdio.h>
#include<cpf.h>

void test_parse_cpf(){
    printf("================== Test Parse CPF ==================\n");
    int passed_cases = 0;
    int cases = sizeof(PARSE_CPF_TEST_CASES)/sizeof(PARSE_CPF_TEST_CASES[0]);
    for(int pos = 0; pos < cases; pos++){
        const char* input = PARSE_CPF_TEST_CASES[pos];
        unsigned long long int expected_output = PARSE_CPF_EXPECTED_OUTPUTS[pos];
        unsigned long long int cpf = parse_cpf(input);
        if(cpf == expected_output){
            printf("Test %d passed ✅\n", pos);
            passed_cases++;
        }else{
            printf("Test %d failed ❌\n", pos);
            printf("\tInput: %s --- Output: %llu --- Expected output: %llu\n",input, cpf, expected_output);
        }
    }
    if(passed_cases == cases){
        printf("========= Test Parse CPF [%d/%d] PASSED ✅ =========\n", passed_cases, cases);
    } else{
        printf("========= Test Parse CPF [%d/%d] FAILED ❌ =========\n", passed_cases, cases);
    }
}

//186.161.140-41 to 18616114041 
unsigned long long int parse_cpf(const char* cpf_with_special_characters){
    unsigned long long int billions;
    unsigned long long int millions;
    unsigned long long int thousands;
    unsigned long long int tenths;

    sscanf(cpf_with_special_characters, "%llu.%llu.%llu-%llu", &billions, &millions, &thousands, &tenths);
    unsigned long long cpf = tenths + 100 * thousands + 100000 * millions + 100000000 * billions;
    return cpf;
}

void print_cpf(long long int cpf){
    printf("%lli\n", cpf);
}