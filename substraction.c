#include "dll.h"
#include <string.h>

/* Function to perform subtraction of two numbers stored in doubly linked lists */
int sub_operation(Dlist **headR, Dlist **tailR, Dlist *tail1, Dlist *tail2)
{

     // Initialize result linked list as empty
    *headR = NULL;
    *tailR = NULL;
    int data1,data2;
    int borrow = 0, sub = 0;

    // Traverse both linked lists from tail to head
    while (tail1 != NULL || tail2 != NULL)
    {
         /* Get digit from first number */
        if(tail1!=NULL)
        {
            data1 = tail1->data;
            tail1 = tail1->prev;
        }
        else
        data1 = 0;
        /* Get digit from second number */
        if(tail2!=NULL)
        {
            data2 = tail2->data;
            tail2 = tail2->prev;
        }
        else
        data2 = 0;
        // Subtract  borrow from current digit
        data1 = data1 - borrow;
        //check borrow needed 
        if (data1 >= data2)
        {
            borrow = 0;
               
        }
        else
        {
            borrow = 1;
            data1 = data1 + 10;
        }
        //perform substraction
        sub = data1 - data2;

         // Insert result digit at beginning of result list 
        if (dl_insert_first(headR, tailR, sub) == FAILURE)
        {
            printf("INFO : Insertion Failure\n");
            return FAILURE;
        }
    }
     // Remove leading zeros from result
    while (*headR!=NULL && (*headR)->data == 0 && (*headR)->next != NULL)
    {
        Dlist *newtemp = *headR;
        *headR = (*headR)->next;
        (*headR)->prev = NULL;
        free(newtemp);
    }
    return SUCCESS;
    
}
