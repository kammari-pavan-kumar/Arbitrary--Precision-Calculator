#ifndef DLL_H
#define DLL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* Macro definitions for function status */
#define SUCCESS 0
#define FAILURE -1

/* Structure definition for doubly linked list node */
typedef struct node
{
	int data;
	struct node *prev;
	struct node *next;
}Dlist;

/* Function to insert node at beginning of DLL */
int dl_insert_first(Dlist **head, Dlist **tail, int data);

/* Function to insert node at end of DLL */
int dl_insert_last(Dlist **head, Dlist **tail, int data);

/* Function to perform addition operation */
int add_operation(Dlist **headR, Dlist **tailR, Dlist *tail1,Dlist *tail2);

/* Function to create two DLLs from input numbers */
int create_two_dll(char *argv[],Dlist **head1,Dlist **head2,Dlist **tail1,Dlist **tail2);

/* Function to validate command line arguments */
int validation(int argc, char *argv[]);

/* Function to print DLL elements */
void print_list(Dlist *head);

/* Function to perform subtraction operation */
int sub_operation(Dlist **headR, Dlist **tailR, Dlist *tail1, Dlist *tail2);

/* Function to perform multiplication operation */
int mul_operation(Dlist **headR,Dlist **tailR,Dlist **headR1, Dlist **tailR1, Dlist **headR2, Dlist **tailR2, Dlist *head1, Dlist *tail1, Dlist *head2, Dlist *tail2 );

/* Function to copy one DLL into another DLL */
int copy_list(Dlist *src_head, Dlist **dest_head, Dlist **dest_tail);

/* Function to delete entire DLL */
int dl_delete_list(Dlist **head, Dlist **tail);

/* Function to perform division operation */
int div_operation(Dlist **headR, Dlist **tailR, Dlist *head1, Dlist *tail1, Dlist *head2,Dlist *tail2, char *argv[]);

/* Function to compare two DLL numbers */
int compare(Dlist *head1, Dlist *head2);

/* Function to validate addition operation and determine final sign */
char add_validation(char *argv[], char *operation);

/* Function to validate subtraction operation and determine final sign */
char sub_validation(char *argv[], char *operation);
#endif

