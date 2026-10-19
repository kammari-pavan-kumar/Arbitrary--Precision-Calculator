#include "dll.h"
#include <string.h>

// Function to validate command line arguments
int validation(int argc, char *argv[])
{
    // Check if correct number of arguments are passed
    // Expected format: ./a.out number1 operator number2
    if (argc != 4)
    {
        printf("INFO: Enter Correct Arguments\n");
        return FAILURE;
    }

    // Validate operator
    // Allowed operators: +, -, x, /
    if (strcmp(argv[2], "+") != 0 && strcmp(argv[2], "-") != 0 && strcmp(argv[2], "x") != 0 && strcmp(argv[2], "/") != 0)
    {
        printf("INFO: Enter Correct Operator\n");
        return FAILURE;
    }

    char *str1 = argv[1];
    int i = 0;
    // Skip sign if number starts with + or -
    if (str1[0] == '+' || str1[0] == '-')
    {
        i = 1;
    }
    // Check if only sign is present without digits
    if (str1[i] == '\0')
    {
        printf("INFO: Invalid number in argv[1]\n");
        return FAILURE;
    }

    // Check each character is a digit
    while (str1[i] != '\0')
    {
        if (str1[i] < '0' || str1[i] > '9')
        {
            printf("INFO: Invalid number in argv[1]\n");
            return FAILURE;
        }
        i++;
    }

    // Validate second number (argv[3])
    char *str2 = argv[3];
    i = 0;

    // Skip sign if number starts with + or -
    if (str2[0] == '+' || str2[0] == '-')
    {
        i = 1;
    }
    // Check if only sign is present without digits
    if (str2[i] == '\0')
    {
        printf("INFO: Invalid number in argv[3]\n");
        return FAILURE;
    }
    // Check each character is a digit
    while (str2[i] != '\0')
    {
        if (str2[i] < '0' || str2[i] > '9')
        {
            printf("INFO: Invalid number in argv[3]\n");
            return FAILURE;
        }
        i++;
    }
    // Return success if all validations pass
    return SUCCESS;
}

/* Function to get the sign of a number string Returns '-' if number is negative
   Otherwise returns '+' */
char get_sign(char *str)
{
    if (str[0] == '-')
        return '-';

    return '+';
}
/* Function to validate addition operation Decides whether actual operation is addition or subtraction
   based on signs of operands */
char add_validation(char *argv[], char *operation)
{
    // Get signs of both numbers
    char sign1 = get_sign(argv[1]);
    char sign2 = get_sign(argv[3]);

    // both numbers are positive
    if (sign1 == '+' && sign2 == '+')
    {
        strcpy(operation, "add");
        return '+';
    }

    // both numbers are negative
    if (sign1 == '-' && sign2 == '-')
    {
        strcpy(operation, "add");
        return '-';
    }

    /* if different signs do subtraction */
    strcpy(operation, "sub");

    char *n1 = argv[1];
    char *n2 = argv[3];
    // Skip sign characters if present
    if (*n1 == '+' || *n1 == '-')
        n1++;

    if (*n2 == '+' || *n2 == '-')
        n2++;

    // finding lengths of both numbers
    int len1 = strlen(n1);
    int len2 = strlen(n2);

    if (len1 > len2)
        return sign1;

    if (len1 < len2)
    {
        char *tmp = argv[1];
        argv[1] = argv[3];
        argv[3] = tmp;
        return sign2;
    }

    // If lengths are equal, compare digit by digit
    int compare = strcmp(n1, n2);

    if (compare > 0)
        return sign1;

    if (compare < 0)
    {
        char *tmp = argv[1];
        argv[1] = argv[3];
        argv[3] = tmp;
        return sign2;
    }
   

    return '+';
}

/* Function to validate subtraction operation Determines whether actual operation is addition or subtraction
   and returns final result sign */
char sub_validation(char *argv[], char *operation)
{
    // Get signs of both numbers
    char sign1 = get_sign(argv[1]);
    char sign2 = get_sign(argv[3]);

    char *n1 = argv[1];
    char *n2 = argv[3];

    // Skip sign characters

    if (*n1 == '+' || *n1 == '-')
        n1++;

    if (*n2 == '+' || *n2 == '-')
        n2++;

    if (sign1 == '+' && sign2 == '-')
    {
        strcpy(operation, "add");
        return '+';
    }

    if (sign1 == '-' && sign2 == '+')
    {
        strcpy(operation, "add");
        return '-';
    }

    int compare;

    int len1 = strlen(n1);
    int len2 = strlen(n2);

    // Compare lengths first
    if (len1 > len2)
        compare = 1;
    else if (len1 < len2)
        compare = -1;
    else
        // If lengths equal, compare strings
        compare = strcmp(n1, n2);

    // operation is subtraction
    strcpy(operation, "sub");

    if (sign1 == '+' && sign2 == '+')
    {
        // If first number is larger or equal
        if (compare >= 0)
            return '+';
        /* If second number is larger,
       swap operands to perform bigger-smaller */
        char *tmp = argv[1];
        argv[1] = argv[3];
        argv[3] = tmp;

        return '-';
    }
    if (sign1 == '-' && sign2 == '-')
    {
        // Swap operands
        if (compare <= 0)
        {
            char *tmp = argv[1];
            argv[1] = argv[3];
            argv[3] = tmp;

            return '+';
        }

        return '-';
    }

    return '+';
}
