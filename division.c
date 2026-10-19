#include "dll.h"
#include <string.h>

/* Function to perform division of two numbers stored in doubly linked lists */
int div_operation(Dlist **headR, Dlist **tailR, Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2, char *argv[])
{

    //take temp1 for traversal
    Dlist *temp1 = head1;

    // Temporary lists for operand and result handling
    Dlist *dest_head = NULL;
    Dlist *dest_tail = NULL;

    Dlist *op_head = NULL;
    Dlist *op_tail = NULL;

    // set result list with NULL
    *headR = NULL;
    *tailR = NULL;
    int count = 0, i = 0;

    //Traverse until temp1 becomes NULL
    while (temp1 != NULL)
    {

        int result;

        //insert current digit in to dll
        if (dl_insert_last(&op_head, &op_tail, temp1->data) == FAILURE)
        {
            return FAILURE;
        }
        /* Remove leading zeros in operand */
        while (op_head != NULL && op_head->data == 0 && op_head->next != NULL)
        {
            Dlist *temp = op_head;
            op_head = op_head->next;
            op_head->prev = NULL;
            free(temp);
        }
        count = 0;
        /* Repeatedly subtract divisor from operand
           until operand becomes smaller */
        while (compare(op_head, head2) >= 0)
        {
            Dlist *hRem = NULL;
            Dlist *tRem = NULL;
            // Pointer to get tail of operand
            Dlist *temp_tail1 = op_head;
            while (temp_tail1->next != NULL)
            temp_tail1 = temp_tail1->next;
            // Perform subtraction  
            if (sub_operation(&hRem, &tRem, temp_tail1, tail2) == FAILURE)
            {
                printf("INFO : SUBTRACTION Operation Failure\n");
                return FAILURE;
            }
            // Delete old operand list
            dl_delete_list(&op_head, &op_tail);
            
            op_head = hRem;
            op_tail = tRem;
            count++;
        }
        /* Insert quotient digit into result list */
        dl_insert_last(headR, tailR, count);

        // move to next digit
        temp1 = temp1->next;
    }
    /* Remove leading zeros from quotient */
    while (*headR != NULL && (*headR)->data == 0 && (*headR)->next != NULL)
    {
        Dlist *newtemp = *headR;
        *headR = (*headR)->next;
        (*headR)->prev = NULL;
        free(newtemp);
    }

    return SUCCESS;
}
// Function to compare two doubly linked list numbers
int compare(Dlist *head1, Dlist *head2)
{
    int i = 0, flag = 0;
    int len1 = 0, len2 = 0;

    // Temporary pointers for traversal
    Dlist *cmp1 = head1;
    Dlist *cmp2 = head2;
    /* Calculate length of first number */
    while (cmp1 != NULL)
    {
        len1++;
        cmp1 = cmp1->next;
    }
    /* Calculate length of second number */
    while (cmp2 != NULL)
    {
        len2++;
        cmp2 = cmp2->next;
    }
     /* Compare lengths first */
    if (len1 < len2)
    {
        return -1;
    }
    if (len1 > len2)
    {
        return 1;
    }
    // Reset pointers for digit comparison
    cmp1 = head1;
    cmp2 = head2;

    /* Compare digit by digit */
    while (cmp1 != NULL && cmp2 != NULL)
    {
        if (cmp1->data > cmp2->data)
        {
            return 1;
        }
        if (cmp1->data < cmp2->data)
        {
            return -1;
        }
        cmp1 = cmp1->next;
        cmp2 = cmp2->next;
    }
    return 0;
}



