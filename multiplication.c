#include "dll.h"
#include <string.h>
/* Function to perform multiplication operation */
int mul_operation(Dlist **headR, Dlist **tailR, Dlist **headR1, Dlist **tailR1, Dlist **headR2, Dlist **tailR2, Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2)
{
    // Initialize all result lists as empty
    *headR1 = NULL;
    *tailR1 = NULL;

    *headR2 = NULL;
    *tailR2 = NULL;

    *headR = NULL;
    *tailR = NULL;
    int mul, carry;
    int n = 0, flag = 0;

    // Temporary pointers for traversal
    Dlist *temp1 = tail1;
    Dlist *temp2 = tail2;

     //Traverse first number from last digit
    while (temp1 != NULL)
    {
        int i = 0;

        // Reset second number pointer
        temp2 = tail2;
        // Clear temporary multiplication result list
        *headR1 = NULL;
        *tailR1 = NULL;
        carry = 0;
       
        /* Multiply one digit of first number with all digits of second number */
        while (temp2 != NULL)
        {
            // Multiply digits and add carry
            int product = (temp1->data * temp2->data + carry);
            // Extract last digit
            mul = product % 10;
            // Extract carry
            carry = product / 10;
            // Insert multiplication result digit
            if (dl_insert_first(headR1, tailR1, mul) == FAILURE)
            {
                printf("INFO : Insertion Failure\n");
                return FAILURE;
            }
            // Move to previous digit
            temp2 = temp2->prev;
        }
        /* Insert remaining carry if present */
        if (carry != 0)
        {
            dl_insert_first(headR1, tailR1, carry);
        }
        // Adding zeros according to place value
        for (int i = 0; i < n; i++)
        {
            dl_insert_last(headR1, tailR1, 0);
        }
         /* If this is first result, copy directly into headR2 */
        if (*headR2 == NULL)
        {
            copy_list(*headR1, headR2, tailR2);
        }
        else
        {
            // Delete previous result list
            dl_delete_list(headR, tailR);
            *headR = NULL;
            *tailR = NULL;
            /* Add current prevoius result with current result */
            if (add_operation(headR, tailR, *tailR1, *tailR2) == FAILURE)
            {
                printf("INFO : ADDITION Operation Failure\n");
            }

            // Delete old copy result
            dl_delete_list(headR2, tailR2);
            *headR2 = NULL;
            *tailR2 = NULL;
            copy_list(*headR, headR2, tailR2);
        }
        // Delete temporary multiplication result list
        dl_delete_list(headR1, tailR1);
        *headR1 = NULL;
        *tailR1 = NULL;
        // Move to next digit of first number
        temp1 = temp1->prev;
        n++;
    }
     // Copy final multiplication result
    copy_list(*headR2, headR, tailR);

    return SUCCESS;
}

/* Function to copy one doubly linked list into another doubly linked list */
int copy_list(Dlist *src_head, Dlist **dest_head, Dlist **dest_tail)
{
    // Initialize destination list
    *dest_head = NULL;
    *dest_tail = NULL;

    // Temporary pointer for traversal
    Dlist *temp = src_head;

    while (temp != NULL)
    {
         // Insert each node data into destination list
        if (dl_insert_last(dest_head, dest_tail, temp->data) == FAILURE)
        {
            return FAILURE;
        }
        temp = temp->next;
    }

    return SUCCESS;
}
/* Function to delete entire doubly linked list */
int dl_delete_list(Dlist **head, Dlist **tail)
{
    Dlist *temp;

    // Traverse and free all nodes
    while (*head != NULL)
    {
        temp = *head;
        *head = (*head)->next;
        free(temp);
    }
    // Set tail as NULL after deletion
    *tail = NULL;

    return SUCCESS;
}