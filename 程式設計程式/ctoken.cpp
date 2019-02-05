#include <stdio.h>
#include <ctype.h>

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

void read_n_print_identifier()
{
    int ch;

    putchar('\"');
    while( (ch = peek_next_input_char()) != EOF )
    {
        if ( isalnum(ch) || ch == '_' )
            putchar(my_getchar());
        else
        {
            putchar('\"');
            return;
        }
    }
}

void read_n_print_number()
{
    int ch;

    while( (ch = peek_next_input_char()) != EOF )
    {
        if ( isdigit(ch) )
            putchar(my_getchar());
        else
            return;
    }
}

int main()
{
    //FILE *fp;
    //fp=freopen("testc.txt","w",stdout);
    char ch;

    while( (ch = peek_next_input_char()) != EOF )
    {
        if ( isblank(ch) || ch == '\n' || ch =='\r' )
        {
            my_getchar();
            continue;
        }

        if ( isalpha(ch) || ch == '_' )
            read_n_print_identifier();
        else if ( isdigit(ch) )
            read_n_print_number();
        else
        {
            putchar(ch);
            my_getchar();
        }

        putchar('\n');
    }

    return 0;
}
