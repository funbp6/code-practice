#include <stdio.h>

char s[100] = "(1+2*3)*((4-5)/6)";

// �p��
int tight(char* s)
{
    int n = 0;
    for (int i=0; s[i]; ++i)
        if (s[i] != ' ')
            s[n++] = s[i];
    s[n++] = '\0';
    return n;
}
int cal(int lv, char op, int rv)
{
    printf("goto cal\n");
    if (op == '+') return lv + rv;
    if (op == '-') return lv - rv;
    if (op == '*') return lv * rv;
    if (op == '/') return lv / rv;
    return 0;   // crash
}

// �M��B��l����m�C�����X�A�G�q�k�ݧ�C
int findop(int L, int R, char op1, char op2)
{
    int c = 0;
    for (int i=R; i>=L; --i)
    {
        if (s[i] == '(') c++;
        if (s[i] == ')') c--;
        if (c == 0 && (s[i] == op1 || s[i] == op2))
            return i;
    }
    return -1;
}

// �^���ƭ�
int number(int L, int R)
{
    int n = 0;
    for (int i=L; i<=R; ++i)
        n = n * 10 + s[i] - '0';
    //printf("goto number n=%d \n",n);
    return n;
}

int parse(int L, int R)
{
    printf("goto parse  L=%d R=%d\n",L,R);
    // �����u���v�̧C���B��Ÿ��C�̥����ѡB�̫�p��C
    int M = findop(L, R, '+', '-');
    printf("%d\n",findop(L, R, '+', '-'));
    // �䤣��C���A�A���u���v���C���B��Ÿ��C
    if (M == -1)
    {
        M=findop(L, R, '*', '/');
        printf("%d\n",findop(L, R, '*', '/'));
    }




    // �B��Ÿ������k�⦡���j�U�h�D�o�T���ƭȡA�M��A�p��C
    // Unspecified Behavior�G�����B�k���A�������I�s�֡I
    if (M != -1)
    {
        printf("parse goto cal\n");
        return cal(parse(L, M-1), s[M], parse(M+1, R));
    }


    // �A��
    if (s[L] == '(' && s[R] == ')')
    {
        printf("goto Parentheses\n");
        return parse(L+1, R-1);
    }


    // �ƭ�
    return number(L, R);
}

int evaluate()
{
    return parse(0, tight(s) - 2);
}


int main()
{
    printf("%d\n", tight(s));
    int a=evaluate();
    //printf("%d",a);
    return 0;

}

