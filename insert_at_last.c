#include "dll.h"

int dl_insert_last(Dlist **head, Dlist **tail, int data)
{
    //create a new node
    Dlist *new = malloc(sizeof(Dlist));
    //validate new pointer with NULL if it is NULL return FAILURE
    if(new == NULL)
    {
        return FAILURE;
    }
    //assign data and address to new node
    new->prev = NULL;
    new->data = data;
    new->next = NULL;
    //check head pointer is NULL or not
    if((*head)==NULL)
    {
        //assign new address to head and tail and return success
        *head = new;
        *tail = new;
        return SUCCESS;
    }
    else
    {
        //assign tail pointer new->ptr
        new->prev = *tail;
        //assign new to  tail pointer next
        (*tail)->next = new;
        //assign tail to tail pointer
        *tail = new;
        return SUCCESS;
        
    }

}