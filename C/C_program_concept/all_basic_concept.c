#include <stdio.h>
#include <stdint.h>

struct Student
{
    int roll_no; 
    float marks;
    char st;
}s;

union Data
{
    uint8_t arr[5];
    int f;
    int fd;
}d;

void size_of_data_type()
{
    struct Student *s;
    union Data *d;

    printf("size of union : %d\n",((char *)(d + 1) - (char *) d));
    printf("size of student structure : %d\n", ((char *)(s + 1) - (char *)s));

}

void normal_concept()
{
    int arr[2][3] = {{1,2,3},{6,7,8}};
    
    // int *p[1] = *arr[1];

    // printf("%d\n",p[0][1]);

    d.f = 0x12345678;
    d.fd = 0x96325418;

    printf("arra: %d\n",d.arr[0]);
    printf("arra: %d\n",d.arr[1]);
    printf("arra: %d\n",d.arr[2]);
    printf("arra: %d\n",d.arr[3]);

    printf("%x\n",d.f);
    printf("sizeof union : %d\n",sizeof(d));
}


void pointer_concept()
{
    int a = 100;
    int *ptr;
    ptr = &a;

    printf("value of a : %d\n", *ptr);

    (*ptr)++;

    printf("pointer after increment : %d\n",*ptr);


    uint8_t arr[5] = {10, 20, 30, 40, 50};

    uint8_t *ptr_arr = arr;

    printf("4th element : %d\n", *(arr + 3));
    printf("3rd element : %d\n", *(ptr_arr + 2));

    // size of pointer is always depends on the architecture of the system. 
    // in 32 bit system size of pointer is 4 bytes and in
    // 64 bit system size of pointer is 8 bytes.
    printf("size of pointer : %d bytes\n",sizeof(ptr));   
}


int array_sum(uint8_t *arr, int size)
{
    int sum = 0, i;

    for(i=0;i<size;i++)
    {
        sum += *(arr + i);
    }

    return sum;
}


//no repeating in an array one or multiple times
void no_repeat_in_array()
{
    int arr[] = {100,300,100,200,100,200,300,400,500,400};

    int n = sizeof(arr)/sizeof(arr[0]);

    int i, j, count;

    for(i = 0; i < n; i++)
    {
        count = 1;

        if(arr[i] == -1)
            continue;

        for(j = i+1; j < n; j++)
        {
            if(arr[i] == arr[j])
            {
                count++;
                arr[j] = -1;
            }
        }

        printf("%d appears %d times\n", arr[i], count);
    }
}

int second_largest_element(int *arr)
{
    int size = (char *)(arr + 5) - (char *) arr;
    int no_of_elements = size/4;
    printf("size of array : %d\n",size);
    int i, large=0, sec_large=0;
    for(i=0;i<no_of_elements;i++)
    {
        if(arr[i] > large)
        {
            sec_large = large;
            large = arr[i];
        }
        else if(arr[i] > sec_large && arr[i] != large)
        {
            sec_large = arr[i];
        }
    }
    return sec_large;
}


int main()
{
    int arr[5] = {10, 20, 30, 40, 50};  

    // printf("size of struct Student: %d bytes\n", sizeof(s));
    // printf("size of union : %d bytes\n", sizeof(d));
    // pointer_concept();

    // normal_concept();
    // int sum_arr = array_sum(arr,5);
    // printf("sum of array elements: %d\n", sum_arr);

    // no_repeat_in_array();

    size_of_data_type();
    int sec_large = second_largest_element(arr);
    printf("second largest element : %d\n",sec_large);
    return 0;
}