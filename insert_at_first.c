#include "dll.h"


int dl_insert_first(Dlist **head, Dlist **tail, int data)
{
    //create new node
    Dlist *newnode = malloc(sizeof(Dlist));
    //validate if it is NULL return FAILURE
    if(newnode == NULL)
    {
        return FAILURE;
    }
    //assign data and pointer to new node
    newnode->prev = NULL;
    newnode->data = data;
    newnode->next = NULL;
    //if list empty assign new node to head pointer
    if((*head)==NULL)
    {
        *head = newnode;
        *tail = newnode;
        return SUCCESS;
    }
    else  //if list not empty insert first node and return success
    {
        newnode->next = *head;
        (*head)->prev = newnode;
        *head = newnode;
        return SUCCESS;
    }
}