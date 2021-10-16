#include<stdio.h>
#include<numbers.h>
#include<stdlib.h>
#include<string.h>
#include<stdbool.h>


Digit* new_Digit(int value) {
    Digit* digit = (Digit*) malloc(sizeof(Digit));
    digit->next = NULL;
    digit->value = value;

    return digit;
}

Number* new_Number(bool isNegative) {
    Number* number = (Number*) malloc(sizeof(Number));
    number->isPositive = ! isNegative;
    number->size = 0;
    number->leastSignificantDigit = NULL;

    return number;
}


void* add_Digit_to_Number(Digit* digit, Number* number){
    number->size +=1;
    digit->next = number->leastSignificantDigit;
    number->leastSignificantDigit = digit;
}

void* print_Number(Number* number) {

    Digit* current_digit = number->leastSignificantDigit;

    while(current_digit != NULL){
        printf("%d", current_digit->value);
        current_digit = current_digit->next;
    }
    printf("\n");

}


Number* get_Number_from_buffer(char* buffer){
    bool is_number_negative  = (int) buffer[0] == '-';
    Number* number = new_Number(is_number_negative);
    int position = 0;
    int size = strlen(buffer);
    
    if(is_number_negative){
        position = 1; 
    }

    for(position; position < size; position ++ ){
        int value = buffer[position] - '0';
        Digit* digit = new_Digit(value);
        add_Digit_to_Number(digit, number);
    }

    return number;
}

bool areNumbersEqual(Number* A, Number* B){
    if(A->isPositive != B-> isPositive) {return false;}
    if(A->size != B->size) {return false;}
    

    Digit* current_A_digit = A->leastSignificantDigit;
    Digit* current_B_digit = B->leastSignificantDigit;

    while(current_A_digit != NULL){
        if((current_A_digit->value && current_B_digit->value) == 0) {return false;}
        current_A_digit = current_A_digit->next;
        current_B_digit = current_B_digit->next;
    }

    return true;
}

bool isNumberBiggerThanNumber(Number* A, Number* B){
    // ---- Corner cases: Numbers with different signals or digits ----- 
    // + > -
    if(A->isPositive && (B-> isPositive == false)){
            return true;
    }

    // - < +
    if((A->isPositive == false) && B-> isPositive){
            return false;
    }
    
    // ++++ > ++
    // ++ < ++++
    if(A->isPositive && B->isPositive){
        if(A->size > B->size) {return true;}
        if(B->size > A->size) {return false;}
    }
    
    // -- > ----
    // ---- < --
    if((A->isPositive == false) && (B->isPositive == false)){
        if(A->size < B->size) {return true;}
        if(A->size > B->size) {return false;}
    }
    // ---- Corner cases: Numbers with same signals and digits -----
    Digit* current_A_digit = A->leastSignificantDigit;
    Digit* current_B_digit = B->leastSignificantDigit;

    Number* digits_inequalities = new_Number(!A->isPositive);
    
    while(current_A_digit != NULL){
        if(current_A_digit->value > current_B_digit->value){
            Digit* isBigger = new_Digit(1);
            add_Digit_to_Number(isBigger, digits_inequalities);
        }
        else if(current_A_digit->value < current_B_digit->value){
            Digit* isSmaller = new_Digit(-1);
            add_Digit_to_Number(isSmaller, digits_inequalities);
        }
        current_A_digit = current_A_digit->next;
        current_B_digit = current_B_digit->next;

    }

    Digit* current_digit = digits_inequalities->leastSignificantDigit;
    while(current_digit != NULL){
        if(current_digit->value == 1){
            return(A->isPositive)?true:false;
        }
        else if(current_digit->value == -1){
            return(A->isPositive)?false:true;
        }
    }
 
    return(A->isPositive)?false:true;
}


void printNumbersComparison(bool isComparison){
    if(isComparison){
        printf("Resultado :: True\n");
    }
    else{
        printf("Resultado :: False\n");
    }
}

void printSoma(Number* number){
    printf("Resultado :: ");
    print_Number(number);
}


void get_soma(Number* first_number, Number*second_number){
    Number* result = new_Number(false);
            
    Digit* current_first_digit = first_number->leastSignificantDigit;
    Digit* current_second_digit = second_number->leastSignificantDigit;
    int first_value;
    int second_value;
    int sum = 0;
    int carry = 0;

    while(current_first_digit != NULL || current_second_digit || NULL){
        first_value = 0;
        second_value = 0;
        sum = 0;
        
        if(current_first_digit != NULL){
            first_value = current_first_digit->value;
            current_first_digit = current_first_digit->next;
        }
        if(current_second_digit != NULL){
            second_value = current_second_digit->value;
            current_second_digit = current_second_digit->next;
        }

        sum = (first_value + second_value + carry)%10;
        carry = (first_value + second_value + carry)/10;

        Digit* digit = new_Digit(sum);
        add_Digit_to_Number(digit, result);
    }

    if(carry > 0) {
        Digit* digit = new_Digit(carry);
        add_Digit_to_Number(digit, result);
    }

    printSoma(result);
}
