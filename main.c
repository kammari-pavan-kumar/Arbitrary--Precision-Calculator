#include "dll.h"
#include <string.h>

/* Main function */
int main(int argc, char *argv[])
{
    int i = 0;
    char option;
    char operation[10]; // stores operation type
    char sign;          // final result sign
    /* Head and tail pointers for input number 1 */
    Dlist *head1 = NULL;
    Dlist *head2 = NULL;
    Dlist *tail1 = NULL;
    Dlist *tail2 = NULL;

    /* Head and tail pointers for result and intermediate results */
    Dlist *headR = NULL;
    Dlist *tailR = NULL;
    Dlist *headR1 = NULL;
    Dlist *headR2 = NULL;
    Dlist *tailR1 = NULL;
    Dlist *tailR2 = NULL;

    /* Validation for command line arguments*/
    if (validation(argc, argv) == FAILURE)
    {
        printf("INFO : Validation Failure\n");
        return 1;
    }

    /* operator sign in argv[2] */
    option = argv[2][0];

    switch (option)
    {
    /* ---------------- ADDITION ---------------- */
    case '+':
    {
        /* Decide whether operation is ADD or SUB based on signs */
        sign = add_validation(argv, operation);
        if (strcmp(operation, "add") == 0)
        {
            head1 = tail1 = NULL;
            head2 = tail2 = NULL;

            /*Create dll*/
            if (create_two_dll(argv, &head1, &head2, &tail1, &tail2) == FAILURE)
            {
                printf("INFO : Creating DLL Failure\n");
                return 1;
            }
            /* Addition operation */
            if (add_operation(&headR, &tailR, tail1, tail2) == FAILURE)
            {
                printf("INFO : ADDITION Operation Failure\n");
            }
        }
        else if (strcmp(operation, "sub") == 0)
        {
            head1 = tail1 = NULL;
            head2 = tail2 = NULL;

            /*Create dll*/
            if (create_two_dll(argv, &head1, &head2, &tail1, &tail2) == FAILURE)
            {
                printf("INFO : Creating DLL Failure\n");
                return 1;
            }
            /* Substraction operation */
            if (sub_operation(&headR, &tailR, tail1, tail2) == FAILURE)
            {
                printf("INFO : ADDITION Operation Failure\n");
            }
        }
        /* Print sign if result is negative */
        if (headR != NULL && sign == '-' && !(headR->data == 0 && headR->next == NULL))
            printf("-");
        /* Print result list */
        print_list(headR);

        return 0;
        break;
    }

    /* ---------------- SUBTRACTION ---------------- */
    case '-':
    {
        /* Decide operation type for subtraction */
        sign = sub_validation(argv, operation);
        if (strcmp(operation, "add") == 0)
        {
            head1 = tail1 = NULL;
            head2 = tail2 = NULL;

            /*Create dll*/
            if (create_two_dll(argv, &head1, &head2, &tail1, &tail2) == FAILURE)
            {
                printf("INFO : Creating DLL Failure\n");
                return 1;
            }
            /* Addition operation */
            if (add_operation(&headR, &tailR, tail1, tail2) == FAILURE)
            {
                printf("INFO : ADDITION Operation Failure\n");
            }
        }
        else if (strcmp(operation, "sub") == 0)
        {
            /* create DLL after swaping operands */

            head1 = tail1 = NULL;
            head2 = tail2 = NULL;

            /*Create dll*/
            if (create_two_dll(argv, &head1, &head2, &tail1, &tail2) == FAILURE)
            {
                printf("INFO : Creating DLL Failure\n");
                return 1;
            }
            /* Perform subtraction */
            if (sub_operation(&headR, &tailR, tail1, tail2) == FAILURE)
            {
                printf("INFO : SUBTRACTION Operation Failure\n");
            }
        }
        /* Print negative sign if required */
        if (headR != NULL && sign == '-' && !(headR->data == 0 && headR->next == NULL))
            printf("-");
        /* Print result */
        print_list(headR);
        return 0;
        break;
    }
    /* ---------------- MULTIPLICATION ---------------- */
    case 'x':
    {
        /* Determine sign for multiplication result */
        if ((argv[1][0] == '-' && argv[3][0] == '-') || (argv[1][0] != '-' && argv[3][0] != '-'))
        {
            sign = '+';
        }
        else
        {
            sign = '-';
        }
        head1 = tail1 = NULL;
        head2 = tail2 = NULL;

        /*Create dll*/
        if (create_two_dll(argv, &head1, &head2, &tail1, &tail2) == FAILURE)
        {
            printf("INFO : Creating DLL Failure\n");
            return 1;
        }
        /* Perform multiplication */
        if (mul_operation(&headR, &tailR, &headR1, &tailR1, &headR2, &tailR2, head1, tail1, head2, tail2) == FAILURE)
        {
            printf("INFO : Multiplication Operation Failure\n");
        }
        /* Print sign if needed */
        if (headR != NULL && sign == '-' && !(headR->data == 0 && headR->next == NULL))
            printf("-");
        /* Print result */
        print_list(headR);
        return 0;
        break;
    }
    /* ---------------- DIVISION ---------------- */
    case '/':
    {
        int i = 0;
        /* Check division by zero */
        while (argv[3][i] != '\0')
        {
            if (argv[3][i] != '0' && argv[3][i] != '+' &&
                argv[3][i] != '-')
            {
                break;
            }
            i++;
        }
        if (argv[3][i] == '\0')
        {
            printf("ERROR: Value can't be Divided by zero\n");
            return 0;
        }
        /* Determine sign of result */
        if ((argv[1][0] == '-' && argv[3][0] == '-') ||
            (argv[1][0] != '-' && argv[3][0] != '-'))
        {
            sign = '+';
        }
        else
        {
            sign = '-';
        }
        head1 = tail1 = NULL;
        head2 = tail2 = NULL;

        /*Create dll*/
        if (create_two_dll(argv, &head1, &head2, &tail1, &tail2) == FAILURE)
        {
            printf("INFO : Creating DLL Failure\n");
            return 1;
        }
        /* perform division */
        if (div_operation(&headR, &tailR, head1, tail1, head2, tail2, argv) == FAILURE)
        {
            printf("INFO : div Operation Failure\n");
        }
        /* Print sign if needed */
        if (headR != NULL && sign == '-' && !(headR->data == 0 && headR->next == NULL))
            printf("-");
        /* Print result */
        print_list(headR);
        return 0;
        break;
    }
    /* ---------------- DEFAULT CASE ---------------- */
    default:
        return 0;
    }

    return SUCCESS;
}
