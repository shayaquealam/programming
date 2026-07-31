#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>


#define MAX 100

struct Node
{
    int data;
    struct Node *next;   
};

struct Node * insert_front(struct Node *head , int data)
{
    struct Node *new_node = (struct Node *)malloc(sizeof(struct Node));

    new_node->data = data;
    new_node->next = head;
    return new_node;    
}

void print_data(struct Node *head)
{
    printf("linked list is : \n");
    while(head != NULL)
    {
        printf("%d ", head->data);
        head = head->next;
    }

    printf("\n");
}

struct Node * delete_front_Node(struct Node *head)
{
    struct Node *temp = head;
    temp = temp->next;
    free(head);
    return temp;
}

struct Node * delete_end_Node(struct Node *head)
{

    if(head->next == NULL)
    {
        free(head);
        return NULL;
    }

    struct Node *temp = head;

    while(temp->next->next != NULL)
    {
        printf("%d ", temp->data);
        temp = temp->next;
    }

    free(temp->next);
    temp->next = NULL;

    return head;
}

    struct Node * insert_end(struct Node *head, int data)
    {
        struct Node *temp = (struct Node *)malloc(sizeof(struct Node));

        temp->next = NULL;
        temp->data = data;

        while(head != NULL)
        {
            printf("%d ",head->data);
            head = head->next;
        }
        head = temp;
        return head;
    }

void reverse_linked_list(struct Node **head)
{
    struct Node *prv = NULL;
    struct Node *curr = *head;
    struct Node *end = NULL;

    while(curr != NULL)
    {
        end = curr->next;
        curr->next = prv;
        prv = curr;
        curr = end;
    }

    *head = prv;

    // return head;
}

struct Node* make_reverse(struct Node *head)
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

//  stack implementation

struct Stack
{
    uint8_t arr[MAX];
    int top;
};

void init_stack(struct Stack *stack)
{
    stack->top = -1;
}

int is_stack_empty(struct Stack *stack)
{
    if(stack->top == -1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_stack_full(struct Stack *stack)
{
    if(stack->top == MAX - 1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void push(struct Stack *stack, int data)
{
    if(is_stack_full(stack))
    {
        printf("stack is full\n");
    }
    else
    {
        stack->top++;
        stack->arr[stack->top] = data;
    }
}

int pop(struct Stack *stack)
{
    int data;
    if(is_stack_empty(stack))
    {
        printf("stack is empty\n");
    }
    else
    {
        data = stack->arr[stack->top];
        stack->top--;
    }

    return data;
}

void print_stack(struct Stack *stack)  
{
    if(is_stack_empty(stack))
    {
        printf("stack is empty\n");
    }
    else
    {
        int i;
        printf("stack elements are : \n");
        for(i=stack->top;i>=0;i--)
        {
            printf("%d ", stack->arr[i]);
        }
        printf("\n");
    }
}

// queue implementation

struct Queue
{
    uint8_t arr[MAX];
    int front;
    int rear;
};

void init_queue(struct Queue *queue)
{
    queue->front = -1;
    queue->rear = 0;
}

int is_queue_empty(struct Queue *queue)
{
    if(queue->front == queue->rear-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

int is_queue_full(struct Queue *queue)
{
    if(queue->rear == MAX-1)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}

void enqueue(struct Queue *queue, int data)
{
    if(is_queue_full(queue))
    {
        printf("queue is full\n");
    }
    else
    {
        queue->arr[queue->rear] = data;
        queue->rear++;
    }
}

int dequeue(struct Queue *queue)
{
    int data;
    if(is_queue_empty(queue))
    {
        printf("queue is empty\n");
    }
    else
    {
        queue->front++;
        data = queue->arr[queue->front];
    }

    return data;
}

void print_queue(struct Queue *queue)
{
    if(is_queue_empty(queue))
    {
        printf("queue is empty\n");
    }
    else
    {
        int i;
        printf("queue elements are : \n");
        for(i=queue->front+1;i<queue->rear;i++)
        {
            printf("%d ", queue->arr[i]);
        }
        printf("\n");
    }
}

void middle_element(struct Node *head)
{
    struct Node *slow_ptr = head;
    struct Node *fast_ptr = head;

    while(fast_ptr != NULL && fast_ptr->next != NULL)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;
    }

    printf("middle element of linked list is : %d\n", slow_ptr->data);
}

void check_circular_linked_list(struct Node *head)
{
    struct Node *slow_ptr = head;
    struct Node *fast_ptr = head;

    while(fast_ptr != NULL && fast_ptr->next != NULL)
    {
        slow_ptr = slow_ptr->next;
        fast_ptr = fast_ptr->next->next;

        if(slow_ptr == fast_ptr)
        {
            printf("linked list is circular\n");
            return;
        }
    }

    printf("linked list is not circular\n");
}

/*#include <stdio.h>
#include <string.h>
#include <stdlib.h>


struct Node
{
    int data;
    struct Node *next;
};

struct Node* insert_data(struct Node *head, int data)
{
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    new_node->data = data;
    new_node->next = head;
    
    return new_node;
}

struct Node* make_reverse(struct Node *head)
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

void print_data(struct Node *head)
{
    while(head != NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
}

int main()
{
    struct Node *head = NULL;
    
    head = insert_data(head,10);
    head = insert_data(head,20);
    head = insert_data(head,30);
    head = insert_data(head,40);
    head = insert_data(head,50);
    
    
    printf("before reverse : \n");
    print_data(head);
    
    printf("\nafter reverse : \n"); 
    head = make_reverse(head);
    print_data(head);
    return 0;
}

*/


void check_palindrom(struct Node *start)
{
    int count=0;

    struct Node *temp = start;

    while(temp != NULL)
    {
        count++;
        temp = temp->next;
    }
}
int main()
{
    struct Node *head = NULL;

    struct Node *head1 = NULL;

    head = insert_front(head, 10);
    head = insert_front(head, 20);
    head = insert_front(head, 30);
    head = insert_front(head, 20);
    head = insert_front(head, 10);


    check_palindrom(head);
    // middle_element(head);
    // check_circular_linked_list(head);

    // head1 = make_reverse(head);


    // print_data(head);
    // head = delete_front_Node(head);
    // print_data(head);
    // head = insert_end(head, 60);
    // head = insert_end(head, 70);
    // head = insert_end(head, 80);
    // head = insert_end(head, 90);
    // print_data(head);

    // head = delete_end_Node(head);
    // printf("after deleting the end node..... linked list is : \n");
    // print_data(head);



    // //stack implementation
    // struct Stack stack;
    // init_stack(&stack);
    // push(&stack, 10);
    // push(&stack, 20);
    // push(&stack, 30);
    // push(&stack, 40);
    // push(&stack, 50);
    // print_stack(&stack);


    // // queue implementation
    // struct Queue queue;
    // init_queue(&queue);
    // enqueue(&queue, 10);
    // enqueue(&queue, 20);
    // enqueue(&queue, 30);
    // enqueue(&queue, 40);
    // enqueue(&queue, 50);
    // print_queue(&queue);

    return 0;
}