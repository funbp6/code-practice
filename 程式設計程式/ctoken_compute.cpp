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

int read_expr( int type[], int integers[], char symbols[][3])
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
    return i;
}
double compute_str(int left, int right ,int type[], int integers[], char symbols[][3])
{
    if(left==right)
            return (double)integers[left];
    int ai=left;
    //printf("left, right=%d , %d\n",left,right);
    while(ai<=right && type[ai]!=1)ai++;
    //printf("ai =%d\n", ai);
    if(type[ai]==1 && ai<=right)
        if(symbols[ai][1] == '+')
        {
            //printf("goto add\n");
            return compute_str(left, ai-1, type, integers, symbols)+compute_str(ai+1, right, type, integers, symbols);
        }
        else
            return compute_str(left, ai-1, type, integers, symbols)-compute_str(ai+1, right, type, integers, symbols);


    int mi=left;
    while(mi<=right && type[mi]!=2)mi++;
    //printf("%c\n", symbols[mi][1]);
    if(type[mi]==2 && mi<=right)
        if(symbols[mi][1] == '*')
        {
            //printf("goto mult\n");
            return compute_str(left, mi-1, type, integers, symbols)*compute_str(mi+1, right, type, integers, symbols);
        }
        else
            return compute_str(left, mi-1, type, integers, symbols)/compute_str(mi+1, right, type, integers, symbols);
}



int main()
{
    //FILE *fp;
    //fp=freopen("testc.txt","w",stdout);
    char ch,s[1000][3];
    int t[1000], in[1000], last_index;
    last_index= read_expr(t, in, s);
    printf("last index= %d\n", last_index);
    printf("types= ");
    for(int j=0;j<last_index;j++)
    {
        printf("%d ",t[j]);
    }

    printf("\n");
    printf("integers= ");
    for (int j=0;j<last_index;j++)
        printf("%d ",in[j]);
    printf("\n");
    for (int j=0;j<last_index;j++)
        {
            for(int k=0;k<3;k++)
                printf("symbols %d = %c ",k,s[j][k]);
            printf("\n");
        }
    printf("\n");

    double ans;
    ans=compute_str(0, last_index-1, t, in, s);
    printf("Answer = %lf", ans);




    return 0;
}
