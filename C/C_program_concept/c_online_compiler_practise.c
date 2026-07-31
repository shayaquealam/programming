#include <stdio.h>
#include <stdlib.h>

struct Node
{
    int data;
    struct Node *next;
};

//insert from start
struct Node* insert_from_start(struct Node *head, int data)
{
    struct Node *new_node = (struct Node *) malloc(sizeof(struct Node));
    
    new_node->data = data;
    new_node->next = head;
    
    return new_node;
}

//insert from end
struct Node* insert_from_end(struct Node *head, int data)
{
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


//print linked list
void print_linked_list(struct Node *head)
{
    while(head != NULL)
    {
        printf("%d ",head->data);
        head = head->next;
    }
}


int count_total_lnked_list_element(struct Node *head)
{
    int count=0;
    
    while(head->next != NULL)
    {
        head = head->next;
        count++;
    }
    count++;
    
    return count;
}

void linked_list_middle_element(struct Node *head, int size)
{
    // // #if 0
    // printf("inside linked\n");
    // struct Node *slow = head;
    // struct Node *fast = head;
    
    // while(slow->next != NULL && fast->next->next != NULL)
    // {
    //     slow = slow->next;
    //     fast = fast->next->next;
    // }
    // printf("before return\n");
    // return slow->data;
    // // #endif
    
#if 1
    if(size%2 != 0)
    {
    size = size/2;
    while(size != 0)
        {
           head = head->next;
           size--;
        }
        printf("middle element  %d\n",head->data);
    }
    else
    {
        size = size/2;
        while(size != 1)
        {
           head = head->next;
           size--;
        }
        
        //printing two middle element:
        printf("middle element :\n");
        printf("%d ",head->data);
        head = head->next;
        printf("%d\n",head->data);
        
    }
    // return head->data;
#endif 
}

void find_element_index_from_start(struct Node *head, int index)
{
    int pos = index;
    while(index>0)
    {
        head = head->next;
        index--;
    }
    
    printf("data at %d position : %d\n", pos, head->data);
}

void find_element_index_from_end(struct Node *head, int index)
{
    int total=0;
    struct Node *temp = head;
    
    while(head != NULL)
    {
        total++;
        head = head->next;
    }
    
    int pos = index;
    index = total-index;
    printf("total element : %d\n",total);
    
    while(index>0)
    {
        temp  = temp->next;
        index--;
    }
    
    printf("data at %d position from end : %d\n", pos, temp->data);
}


struct Node* delete_first_node(struct Node *head)
{
    struct Node *temp;
    temp = head->next;
    free(head);
    return temp;
}

/* struct Node* delete_last_node(struct Node *head)
{
    while(head->next != NULL)
    {
        head = head->next;
    }
    head = NULL;
    temp = head;
    free(head->next);
    return head;
} */


void sum_of_all_element(struct Node *head)
{
    int sum=0;

    while(head->next != NULL)
    {
        head = head->next;
        sum = sum + head->data;
    }

    printf("sum of all element : %d\n",sum);
}


int main()
{
    struct Node *head = NULL;
    
    // head = insert_from_start(head, 32);
    // head = insert_from_start(head, 31);
    // head = insert_from_start(head, 30);
    // head = insert_from_start(head, 29);
    // head = insert_from_start(head, 28);
    
    head = insert_from_end(head, 32);
    head = insert_from_end(head, 31);
    head = insert_from_end(head, 30);
    head = insert_from_end(head, 29);
    head = insert_from_end(head, 28);
    head = insert_from_end(head, 27);
    head = insert_from_end(head, 26);
    
    print_linked_list(head);
    
    int count = count_total_lnked_list_element(head);
    
    printf("\ntotal no of linked list element : %d\n",count);
    
    linked_list_middle_element(head,count);
    
    find_element_index_from_start(head,5);
    
    find_element_index_from_end(head,5);

    sum_of_all_element(head);
    
    head = delete_first_node(head);
    
    // head = delete_last_node(head);
    // printf("after deleting the first node \n");
    print_linked_list(head);

    sum_of_all_element(head);
    
}


/*#include <stdio.h>
#include <stdint.h>

#define MAX 100
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


int main()
{
    // queue implementation
    struct Queue queue;
    init_queue(&queue);
    enqueue(&queue, 10);
    enqueue(&queue, 20);
    enqueue(&queue, 30);
    enqueue(&queue, 40);
    enqueue(&queue, 50);
    print_queue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    dequeue(&queue);
    print_queue(&queue);
    printf("front : %d, rear : %d\n",queue.front, queue.rear);
} */