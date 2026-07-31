
#include <stdio.h>
#include <string.h>

int string_length()
{
    char str[] = "my name is shayaque alam";

    int i=0,len=0;

    while(str[i] != '\0')
    {
        len++;
        i++;
    }

    printf("length of the string : %d\n",len);
    return 0;
}

void string_copy()
{
    char str[] = "my name is shayaque alam";
    char str_cpy[30];

    int i=0;

    while(str[i] != '\0')
    {
        str_cpy[i] = str[i];
        i++;
    }
    str_cpy[i] = '\0';
    printf("copied string : %s\n",str_cpy);
    return;
}

void string_addition()
{
    printf("inside string addition\n");
    char str1[] = "my name is shayaque alam";
    char str2[] = "whats your name";

    int len1 = strlen(str1);
    int len2 = strlen(str2);

    char str_add[len1+len2];

    int i=0,j=0;

    while(str1[i] != '\0')
    {
        str_add[i] = str1[i];
        i++;
    }

    str_add[i] = ' ';
    i++;

    while(str2[j] != '\0')
    {
        str_add[i] = str2[j];
        i++;
        j++;
    }

    str_add[i] = '\0';
    printf("string after addition : %s\n",str_add);
}

void string_reverse()
{
    char str[] = "my name is shayaque alam";
    int len = strlen(str);
    int i=0;
    char temp;

    for(i=0;i<len/2;i++)
    {
        temp = str[len-i-1];
        str[len-i-1] = str[i];
        str[i] = temp;
    }

    printf("reverse string : %s\n",str);
}

void plindrom_string_check()
{
    char str[] = "123456654331";

    int len = strlen(str);
    int i,flag=0;

    for(i=0;i<(len/2);i++)
    {
        if(str[i] == str[len-i-1])
        {
            continue;
        }
        else{
            flag=1;
            break;
        }
    }

    if(flag==0)
    {
        printf("plindrom string\n");
    }
    else
    {
        printf("not plindrom string\n");
    }
}

void reverse_string_with_word()
{
    char str[] = "my name is shayaque alam";
    printf("original string : %s\n",str);

    int len = strlen(str);
    int i=0;
    char temp;
    for(i=0;i<len/2;i++)
    {
        temp = str[len-i-1];
        str[len-i-1] = str[i];
        str[i] = temp;
    }

    int start=0,end=0;

    for(i=0;i<=len;i++)
    {
        if(str[i] == ' ' || str[i] == '\0')
        {
           end = i-1;
           while(start < end)
            {
                temp = str[end];
                str[end] = str[start];
                str[start] = temp;

                start++;
                end--;
            }
            start = i+1;
        }
    }
    printf("reverse string : %s\n",str);
}

void reverse_each_word()
{
    char str[] = "Hello Shayaque Alam";
    int len = strlen(str);
    int i=0,start=0,end=0;
    char temp;

    // printf("length of string : %d\n",len);

    for(i=0;i<=len;i++)
    {
        if(str[i] == ' ' || str[i] == '\0')
        {
            end = i-1;
            
            while(start < end)
            {
                temp= str[end];
                str[end] = str[start];
                str[start] = temp;
                start++;
                end--;
            }
            start = i+1;
        }
    }

    printf("string after reverse each word : %s\n",str);
}


int main()
{
    string_copy();
    string_length();
    string_addition();
    string_reverse();
    plindrom_string_check();
    reverse_string_with_word();
    reverse_each_word();
    return 0;
}