#include<stdio.h>

char my_buffer;
int is_my_buffer_filled =0;

char my_getchar();
void my_buffer_fill(char ch);

char my_getchar()
{
    char c;
    if(is_my_buffer_filled==0)
    {
        //is_my_buffer_filled=1;
        c=getchar();
        return c;
    }
    else
    {
        is_my_buffer_filled=0;
        return my_buffer;
    }
}


void my_buffer_fill(char ch)
{
    is_my_buffer_filled=1;
    my_buffer=ch;
}


/*
int main()
{
    printf("%c", my_buffer);
    my_getchar();
    char tmp;
    printf("0. %d %c %c\n",is_my_buffer_filled,tmp,my_buffer);
    tmp=my_getchar();
    printf("1. %d %c %c\n",is_my_buffer_filled,tmp,my_buffer);
    tmp=my_getchar();
    printf("2. %d %c %C\n",is_my_buffer_filled,tmp,my_buffer);
    tmp=my_getchar();
    printf("3. %d %c %c\n",is_my_buffer_filled,tmp,my_buffer);
    my_buffer_fill(tmp);
    printf("fill %d %c %c\n",is_my_buffer_filled,tmp,my_buffer);
    tmp=my_getchar();
    printf("4. %d %c %c\n",is_my_buffer_filled,tmp,my_buffer);

    return 0;
}*/
