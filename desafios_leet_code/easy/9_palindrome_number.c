// https://leetcode.com/problems/palindrome-number/
/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdbool.h>
#include <math.h>
#include <stdlib.h>
#include <stdio.h>

int* extract_numbers(int x, int quantity_numbers){
    int* numbers = calloc(quantity_numbers, sizeof(int));
    int number_index = 0;
    for (int i = quantity_numbers - 1; i >= 0; i--){
        numbers[number_index] = x / pow(10, i);
        number_index++;
    }
    return numbers;
}

bool verify_symmetry(int* numbers, int quantity_numbers){
    for (int i = 0; i < quantity_numbers / 2; i++){
        if (numbers[i] != numbers[quantity_numbers - 1 - i]){
            return false;
        }
    }

    return true;
}

bool isPalindrome(int x){
    int quantity_numbers = (int)log10(x) + 1;
    int* numbers = extract_numbers(x, quantity_numbers);
    if (verify_symmetry(numbers, quantity_numbers)){
        return true;
    }
    return false;
}


int main()
{
    bool result = isPalindrome(464);
    printf("%d\n", result);
}
