#include <stdio.h>
#include <stdint.h>
#include <stdbool.h>

void bit_set(uint32_t no, int pos)
{
    no = no | (1 << pos);
    printf("number after bit setting : %x\n",no);
}

void bit_clear(uint32_t no, int pos)
{
    no = no & ~(1 << pos);
    printf("number after bit clearing : %x\n",no);
}

void bit_toggle(uint32_t no, int pos)
{
    no = no ^ (1 << pos);
    printf("number after bit toggling : %x\n",no);
}

void bit_check(uint32_t no, int pos)
{
    if(no & (1 << pos))
        printf("bit is set\n");
    else
        printf("bit is not set\n");
}

void number_reverse_1_byte(uint32_t no)
{
    uint32_t temp=0;

    temp = temp | ((no >> 28) & 0xf);
    no = no << 4;

    temp = temp | ((no >> 24) & 0xf0);
    no = no << 4;

    temp = temp | ((no >> 20) & 0xf00);
    no = no << 4;

    temp = temp | ((no >> 16) & 0xf000);
    no = no << 4;

    temp = temp | ((no >> 12) & 0xf0000);
    no = no << 4;

    temp = temp | ((no >> 8) & 0xf00000);
    no = no << 4;

    temp = temp | ((no >> 4) & 0xf000000);
    no = no << 4;

    temp = temp | (no & 0xf0000000);

    printf("number after reverse with 1 byte : %x\n",temp);
}


void number_reverse_2_byte(uint32_t no)
{
    uint32_t temp=0;

    temp = temp | ((no >> 24) & 0xff);
    no = no << 8;

    temp = temp | ((no >> 16) & 0xff00);
    no = no << 8;

    temp = temp | ((no >> 8) & 0xff0000);
    no = no << 8;

    temp = temp | (no & 0xff000000);

    printf("number after reverse with 2 byte : %x\n",temp);
}


void change_some_bit(uint32_t no)
{
    no = (no & 0xff0000ff) | ((no & 0x00ff0000) >> 8) | ((no & 0x0000ff00) << 8);
    printf("number after changing some bit : %x\n",no);
}

void change_last_byte(uint32_t no)
{
    no = (no & 0x00ffff00) | ((no & 0xff000000) >> 24) | ((no & 0x000000ff) << 24);
    printf("number after changing last byte : %x\n",no);
}

void swap_bit(uint32_t no)
{
    no = (no & 0xfff00fff) | ((no & 0x000f0000) >> 4) | ((no & 0x0000f000) << 4);
    printf("number after swapping bits : %x\n",no);

    // only swap 1st and last byte
    no = (no & 0x0ffffff0) | ((no & 0xf0000000) >> 28) | ((no & 0x0000000f) << 28);
    printf("number after swapping bits : %x\n",no); 

    // only swap 1st and 2nd byte
    no = (no & 0xffffff00) | ((no & 0x000000f0) >> 4) | ((no & 0x0000000f) << 4);
    printf("number after swapping bits : %x\n",no); 
}

void swap_only_bit(uint32_t no, int pos1, int pos2)
{
    #if 1
    bool bit1, bit2;
    bit1 = (no >> pos1) & 1;
    bit2 = (no >> pos2) & 1;

    if(bit1 != bit2)
    {
        no = no ^ (1 << pos1);
        no = no ^ (1 << pos2);
    }
    printf("after swapping two bit : %x\n",no);
    #endif
    

    #if 0
    no = (no & ~(1 << pos1)) | (((no >> pos2) & 1) << pos1);
    no = (no & ~(1 << pos2)) | (((no >> pos1) & 1) << pos2);
    printf("after swapping two bit : %x\n",no);
    #endif

}

void check_even_odd(int number)
{
    if(!(number & 1))
    {
        printf("even number\n");
    }
    else
    {
        printf("odd number\n");
    }
}

void check_bit_set(int no, int bit_pos)
{
    if(no & (1 << bit_pos))
    {
        printf("bit is set\n");
    }
    else
    {
        printf("bit is not set\n");
    }
}


void count_total_bit_set(uint32_t no)
{
    int count = 0;

    while(no)
    {
        count = count + (no & 1);
        no = no >> 1;
    }
    printf("total bit set in number : %d\n",count);
}

void check_pow_2(uint32_t no)
{
    if(!(no & (no - 1)))
    {
        printf("number is a power of 2\n");
    }
    else
    {
        printf("number is not a power of 2\n");
    }
}


void print_binary(uint32_t no)
{
    int i;
    bool flag;

    for(i=31;i>=0;i--)
    {
        flag = (no >> i) & 1;
        printf("%d", flag);
    }
    printf("\n");
}

void swap_two_number(uint8_t a, uint8_t b)
{
    a = a ^ b;
    b = a ^ b;
    a = a ^ b;

    printf("after swapping a : %d, b : %d\n",a,b);
}



int main()
{
    uint32_t no = 0x12345678;
    // int pos = 3;

    // printf("original number : %x\n",no);

    // bit_set(no,pos);
    // bit_clear(no,pos);
    // bit_toggle(no,pos);
    // bit_check(no,0);

    // number_reverse_1_byte(no);

    // number_reverse_2_byte(no);

    // change_some_bit(no);

    // swap_bit(no);

    // int number = 168;
    // check_even_odd(number);

    // check_bit_set(no, 0);

    // count_total_bit_set(no);

    // check_pow_2(number);

    // print_binary(no);

    // uint8_t a = 10, b = 20;
    
    // swap_two_number(a,b);

    swap_only_bit(no,7,1);

    // change_last_byte(0x12345678);

    return 0;

}