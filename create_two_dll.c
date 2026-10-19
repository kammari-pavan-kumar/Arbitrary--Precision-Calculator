#include "dll.h"

/* Function to create two doubly linked lists from the numbers passed through command line arguments */
int create_two_dll(char *argv[],Dlist **head1,Dlist **head2,Dlist **tail1,Dlist**tail2)
{
    // Store input numbers from command line
    char *str1 = argv[1];
    char *str2 = argv[3];
    int i=0,data,buff;
    /* Skip sign character + or - for first number */
    if(str1[0] == '+' || str1[0] == '-')
        i = 1;

    /* Insert each digit of first number into first doubly linked list */
    while(str1[i] != '\0')
    {
        data = (str1[i] - '0');
        if(dl_insert_last(head1, tail1, data) == FAILURE)
        {
            printf("INFO : Insertion Failure\n");
            return FAILURE;
        }
        i++;
    }

    // Reset index for second number
    i=0;
    /* Skip sign character (+ or -) for second number */
    if(str2[0] == '+' || str2[0] == '-')
        i = 1;
    /* Insert each digit of first number into second doubly linked list */
    while(str2[i]!='\0')
    {
        buff = (str2[i]-'0');
        if (dl_insert_last(head2, tail2, buff) == FAILURE) //pass by reference
		{
			printf("INFO : Insertion Failure\n");
            return FAILURE;
		}
        i++;
    }
    
    return SUCCESS;
}
