#include "dll.h"
#include<string.h>

/* Function to perform addition of two numbers stored in doubly linked lists */
int add_operation(Dlist **headR, Dlist **tailR, Dlist *tail1,Dlist *tail2)
{
    // Initialize result linked list as empty
    *headR = NULL;
    *tailR = NULL;
    int flag = 0, add=0, lastdigit;

    // Traverse both linked lists from tail to head
    while(tail1 != NULL || tail2 != NULL)
    {
        // Start addition with carry
        add = flag;

        /* Add digit from first number if available */
        if(tail1!=NULL)
        {
            add = add + tail1->data;
            tail1 = tail1->prev;
        }

        /* Add digit from second number if available */
        if(tail2!=NULL)
        {
            add = add + tail2->data;
            tail2 = tail2->prev;
        }
        // Extract carry value
        flag = add/10;
        // Extract last digit of sum
        lastdigit = add%10;
        /* Insert result digit at beginning of result list */
        if (dl_insert_first(headR, tailR, lastdigit) == FAILURE) 
        {
            printf("INFO : Insertion Failure\n");
            return FAILURE;
        }
        
    }
    /* If carry remains after loop, insert it at beginning */
    if(flag!=0)
    {
        dl_insert_first(headR, tailR, flag);
    }
    
    return SUCCESS;

}
