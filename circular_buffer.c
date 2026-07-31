#include <stdio.h>
#include <stdint.h>

#define MAX_SIZE    5

struct circular
{
    int front;
    int rear;
    int count;
    uint8_t arr[MAX_SIZE];
};

void init_circular(struct circular *cs)
{
    cs->front = 0;
    cs->rear = 0;
    cs->count = 0;
}

int is_empty(struct circular *cs)
{
    if(cs->count == 0)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int is_full(struct circular *cs)
{
    if(cs->count == MAX_SIZE)
    {
        return 1;
    }
    else
    {
        return 0;
    }
}


int insert_element(struct circular *cs, uint8_t data)
{
    if(is_full(cs))
    {
        printf("circular buffer is full\n");
        return -1;
    }
    
    cs->arr[cs->rear] = data;
    cs->rear = (cs->rear + 1) % MAX_SIZE;
    cs->count++;
    
    return 0;
}

int pop_element(struct circular *cs)
{
    int data;
    if(is_empty(cs))
    {
        printf("circular buffer is empty\n");
        return -1;
    }
    
    data = cs->arr[cs->front];
    cs->front = (cs->front + 1) % MAX_SIZE;
    cs->count--;
    return data;
}

int print_element(struct circular *cs)
{
    if(is_empty(cs))
    {
        printf("circular buffer is empty\n");
        return -1;
    }
    
    int count = cs->count;
    int start = cs->front;
    
    while(count != 0)
    {
        printf("%c ",cs->arr[start]);
        start = (start + 1)% MAX_SIZE;
        count--;
    }
    
    return 0;
}

int main()
{
    struct circular cs;
    init_circular(&cs);
    
    insert_element(&cs,'h');
    insert_element(&cs,'e');
    insert_element(&cs,'l');
    insert_element(&cs,'l');
    insert_element(&cs,'o');
    
    print_element(&cs);
}