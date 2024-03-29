#include<stdio.h>
#include <stdlib.h>
 
// A linked list node
struct node
{
  int data;
  struct node *next;
};
 

void push(struct node** head_ref, int new_data)
{
    
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
 
    
    new_node->data  = new_data;
 
    
    new_node->next = (*head_ref);
 
 
    (*head_ref)    = new_node;
}
 

void insertAfter(struct node* prev_node, int new_data)
{
    
    if (prev_node == NULL)
    {
      printf("the given previous node cannot be NULL");
      return;
    }
 
    
    struct node* new_node =(struct node*) malloc(sizeof(struct node));
 
    
    new_node->data  = new_data;
 
    
    new_node->next = prev_node->next;
 
    
    prev_node->next = new_node;
}
 

void append(struct node** head_ref, int new_data)
{
    
    struct node* new_node = (struct node*) malloc(sizeof(struct node));
 
    struct node *last = *head_ref;  
 
    
    new_node->data  = new_data;
 
    
    new_node->next = NULL;
 
    if (*head_ref == NULL)
    {
       *head_ref = new_node;
       return;
    }
 
    while (last->next != NULL)
        last = last->next;
 
    last->next = new_node;
    return;
}
 

void printList(struct node *node)
{
  while (node != NULL)
  {
     printf(" %d ", node->data);
     node = node->next;
  }
}
 

int main()
{
    struct node* head = NULL;
 
  
  append(&head, 2);
 
  
  push(&head, 1);
 
  push(&head, 5);
 
  append(&head, 9);
 
   insertAfter(head, 8);
 
 
  printf("\n Created Linked list is: ");
  printList(head);
 
  getchar();
  return 0;
}
