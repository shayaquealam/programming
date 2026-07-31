#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>

#define     MULTIPLE_LOOP       0
#define     SINGLE_LOOP         1

void find_second_largest_element()
{

    #if MULTIPLE_LOOP
    int arr[10] = {445,43,200,300,234,678,333,450,123,677};
    
    int size = sizeof(arr)/sizeof(arr[0]);
    
    int large =0, sec_large =0, third_large=0, i;
    
    for(i=0;i<size;i++)
    {
        if(large < arr[i])
        {
            large = arr[i];
        }
    }
    
    printf("large : %d\n",large);
     
    for(i=0;i<size;i++)
    {
        if(large != arr[i] && sec_large < arr[i])
        {
            sec_large = arr[i];
        }
    }
    
    printf("second large : %d\n",sec_large);
    
    for(i=0;i<size;i++)
    {
        if(large != arr[i] && sec_large != arr[i] && third_large < arr[i])
        {
            third_large = arr[i];
        }
    }
    printf("third large : %d\n",third_large);
    #endif

    #if SINGLE_LOOP
    int arr[10] = {445,43,200,300,234,678,333,450,123,670};
    
    int size = sizeof(arr)/sizeof(arr[0]);
    
    int large =0, sec_large =0, third_large=0, i;
    
    for(i=0;i<size;i++)
    {
        if(large < arr[i])
        {
            sec_large = large;
            large = arr[i];
        }
        
        if(large != arr[i] && sec_large < arr[i])
        {
            third_large = sec_large;
            sec_large = arr[i];
        }
        
        if(large != arr[i] && sec_large != arr[i] && third_large < arr[i])
        {
            third_large = arr[i];
        }
    }
    printf("large : %d\n",large);
    printf("second large : %d\n",sec_large);
    printf("third large : %d\n",third_large);
    #endif

}



/* #include <stdio.h>

int sum;

int* add(int a,int b)
{
    sum = a+b;
    return &sum;
}

int main()
{
    int *ptr = add(10,20);
    printf("sum of two number : %d\n",*ptr);
    return 0;
}
 */

/* #include <stdio.h>
#include <string.h>

int main()
{
    char *str[] = {"welcome","to","Bengaluru","function","for"};

    printf("length of string : %d %d\n",strlen(str[0]),strlen(*str));
} */



#include <stdio.h>
#include <stdint.h>
#include <stdlib.h>
// #include <pthread.h>

// pthread_mutex_t lock;
// pthread_cond_t cond;

// int turn = 0;
// int a = 10, b = 5;

struct Node 
{
    int data;
    struct Node *node;
};

int count =0;
struct Node *insert_element(struct Node *head, int data)
{
    struct Node  *new_node= (struct Node *)malloc(sizeof(struct Node));
    
    new_node->data =data;
    new_node->node = head;
    
    count++;
    return new_node;
}

void find_element(struct Node *head,int count)
{
    while(count!=0)
    {
        head = head->node;
        count--;
    }
    printf("data : %d\n",head->data);
}


/*void* add(void* arg)
{
    pthread_mutex_lock(&lock);

    while(turn != 0)
        pthread_cond_wait(&cond, &lock);

    printf("Addition = %d\n", a + b);

    turn = 1;
    pthread_cond_signal(&cond);

    pthread_mutex_unlock(&lock);

    return NULL;
}

void* sub(void* arg)
{
    pthread_mutex_lock(&lock);

    while(turn != 1)
        pthread_cond_wait(&cond, &lock);

    printf("Subtraction = %d\n", a - b);

    pthread_mutex_unlock(&lock);

    return NULL;
}

int main()
{
    pthread_t t1, t2;

    pthread_mutex_init(&lock, NULL);
    pthread_cond_init(&cond, NULL);

    pthread_create(&t1, NULL, add, NULL);
    pthread_create(&t2, NULL, sub, NULL);

    pthread_join(t1, NULL);
    pthread_join(t2, NULL);

    pthread_mutex_destroy(&lock);
    pthread_cond_destroy(&cond);

    return 0;
}
*/

int main()
{
    struct Node *head = NULL;
    
    head = insert_element(head,10);
    head = insert_element(head,20);
    head = insert_element(head,30);
    head = insert_element(head,40);
    head = insert_element(head,50);
    
    int n = 4;
    find_element(head,count-4);
    
    printf("count :%d",count);

    find_second_largest_element();
    
    
    return 0;
}