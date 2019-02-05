#include <stdio.h>
#include <ctype.h>
#include <stdlib.h>

/***************

    Utility:  My-Buffered-Getchar

****************/


int is_my_buffer_filled = 0;
char my_buffer;

int my_getchar()
{
    if ( is_my_buffer_filled )
    {
        is_my_buffer_filled = 0;
        return my_buffer;
    }
    else
        return getchar();
}

void my_buffer_fill( char ch )
{
    is_my_buffer_filled = 1;
    my_buffer = ch;
}


/*****************

    Utility 2 : Peek next char without extracting it

******************/

char peek_next_input_char()
{
    char ch = my_getchar();
    my_buffer_fill(ch);

    return ch;
}


/******************

*******************/

int read_n_print_number()
{
    int ch,i=0,a;
    char cint[100];
    ch=peek_next_input_char();
    while(isdigit(ch))
    {
        cint[i]=ch;
        my_getchar();
        ch=peek_next_input_char();
        i++;
    }
    a=atoi(cint);
    return a;
}

void read_expr( int type[], int integers[], char symbols[][3])
{
    int i=0;
    char ch;
    while((ch = peek_next_input_char()) != ';')
    {
        if ( isblank(ch) || ch == '\n' || ch =='\r' )
        {
            my_getchar();
            continue;
        }
        if(isdigit(ch))
        {
            type[i]=0;
            integers[i]=read_n_print_number();
            symbols[i][0]='\0';
            symbols[i][1]='\0';
            symbols[i][2]='\0';
            i++;
        }
        else
        {
            if(ch == '+' || ch == '-' )type[i]=1;
            if(ch == '*' || ch == '/' )type[i]=2;
            if(ch == '(' || ch == ')' )type[i]=3;
            integers[i]=0;
            symbols[i][0]='\"';
            symbols[i][1]=ch;
            symbols[i][2]='\"';
            my_getchar();
            i++;
        }
    }
    return;
}
void compute_str(int left, int right ,int type[], int integers[], char symbols[][3])
{


    return;
}



int main()
{
    //FILE *fp;
    //fp=freopen("testc.txt","w",stdout);
    char ch,s[10][3];
    int t[10]={0},in[10],test;
    read_expr(t, in, s);

    printf("types= ");
    for (int j=0;j<10;j++)
        printf("%d ",t[j]);
    printf("\n");
    printf("integers= ");
    for (int j=0;j<10;j++)
        printf("%d ",in[j]);
    printf("\n");
    for (int j=0;j<10;j++){
        for(int k=0;k<3;k++)
            printf("symbols %d = %c ",k,s[j][k]);
        printf("\n");
        }printf("\n");
    return 0;
}
