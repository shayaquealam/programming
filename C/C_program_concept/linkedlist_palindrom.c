/******************************************************************************

                            Online C Compiler.
                Code, Compile, Run and Debug C program online.
Write your code in this editor and press "Run" button to compile and execute it.

*******************************************************************************/

#include <stdio.h>
#include <stdlib.h>

struct Node 
{
    int data;
    struct Node *next;
};


struct Node* insert_element(struct Node *head, int data)
{
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    
    new_node->data = data;
    new_node->next = head;
}

int print_linkedlist(struct Node *head)
{
    if(head == NULL)
    {
        printf("linked list is empty\n");
        return -1;
    }
    
    while(head != NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
    return 0;
}

int total_element(struct Node *head)
{
    int count;
    while(head != NULL)
    {
        count++;
        head = head->next;
    }
    return count;
}

struct Node* middle_element_delete(struct Node *head, int size)
{
    struct Node *prv = NULL;
    struct Node *curr=head;
    size = size/2;
    if(size%2 == 0)
    {
        while(size!=0)
        {
            prv = curr;
            curr = curr->next;
            size--;
        }
        prv->next = curr->next;
        // free(curr);
        printf("\nmiddle element : %d\n",head->data);
    }
    
    return head;
}

struct Node *copyLinkedList(struct Node *head)
{
    if (head == NULL)
        return NULL;

    struct Node *copyHead = NULL;
    struct Node *tail = NULL;

    while (head != NULL)
    {
        struct Node *newNode = (struct Node *) malloc(sizeof(struct Node));

        newNode->data = head->data;
        newNode->next = NULL;

        if (copyHead == NULL)
        {
            copyHead = newNode;
            tail = newNode;
        }
        else
        {
            tail->next = newNode;
            tail = newNode;
        }

        head = head->next;
    }

    return copyHead;
}

struct Node* check_palindrom(struct Node *head)
{
    struct Node *temp1 = copyLinkedList(head);
   
    struct Node *prv = NULL;
    struct Node *curr = head;
    struct Node *end = NULL;
    
    struct Node *temp = head;
    
    
    int count=0;
    while(temp != NULL)
    {
        temp = temp->next;
        count++;
    }
    
    printf("\ncount : %d\n",count);
    while(curr != NULL)
    {
        end = curr->next;
        curr->next = prv;
        prv = curr;
        curr = end;
    }
    
    struct Node *prv1 = prv;
    
    count = count/2;
    int flag=0;

    while(count != 0)
    {
        printf("temp1 data : %d\n",temp1->data);
        printf("prv data : %d\n",prv->data);
        if(temp1->data == prv->data)
        {
            count--;
            temp1 = temp1->next;
            prv = prv->next;
            continue;
        }
        else
        {
            flag=1;
            break;
        }
    }
    
    if(!flag)
    {
        printf("\npalindrom number\n");
    }
    else
    {
        printf("\nnot a palindrom number\n");
    }
    
    return prv1;
}

int main()
{
    struct Node *head = NULL;
    
    head = insert_element(head, 10);
    head = insert_element(head, 20);
    head = insert_element(head, 30);
    head = insert_element(head, 20);
    head = insert_element(head, 10);

    print_linkedlist(head);
    
    int count = total_element(head);
    
    // head = middle_element_delete(head,count);
    printf("\n");
    print_linkedlist(head);
    
    head = check_palindrom(head);
    
    print_linkedlist(head);
    return 0;
}