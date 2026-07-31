#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
};

struct Node* insert_from_end(struct Node *head, int data)
{
    // struct Node *temp;
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    
    new_node->data = data;
    new_node->next = NULL;
    
    if(head == NULL)
    {
        head = new_node;
    }
    else
    {
        struct Node *temp = head;
        
        while(temp->next != NULL)
        {
            temp =temp->next;
        }
        temp->next = new_node;
    }
    
    return head;
}

void middle_element(struct Node *head)
{
    struct Node *slow = head;
    struct Node *fast = head;
    
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    
    printf("\nmiddle element : %d\n",slow->data);
}

void check_circular_linked_list(struct Node *head)
{
    struct Node *slow = head;
    struct Node *fast = head;
    
    while(fast != NULL && fast->next != NULL)
    {
        slow = slow->next;
        fast = fast->next->next;
    }
    if(slow == fast)
        {
            printf("linked list is circular\n");
        }
        else
        {
            printf("not a circular linked list\n");
        }
}

void print_linked_list(struct Node *head)
{
    while(head != NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
}

struct Node* reverse_linked_list(struct Node *head)
{
    struct Node *prv = NULL;
    struct Node *curr = head;
    struct Node *end = NULL;
    
    while(curr != NULL)
    {
        end = curr->next;
        curr->next = prv;
        prv = curr;
        curr = end;
    }
    
    return prv;
}


int main()
{
    struct Node *head = NULL;
    head = insert_from_end(head,10);
    head = insert_from_end(head,11);
    head = insert_from_end(head,12);
    head = insert_from_end(head,13);
    head = insert_from_end(head,14);
    head = insert_from_end(head,15);
    head = insert_from_end(head,16);
    
    // print_linked_list(head);
    
    head = reverse_linked_list(head);
    
    printf("\nafter reversing the linked list\n");
    
    print_linked_list(head);
    
    middle_element(head);
    
    check_circular_linked_list(head);
}