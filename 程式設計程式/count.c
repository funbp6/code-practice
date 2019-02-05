#include <stdio.h>

char s[100] = "(1+2*3)*((4-5)/6)";

// 計算
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

// 尋找運算子的位置。左結合，故從右端找。
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

// 擷取數值
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
    // 先找優先權最低的運算符號。最先分解、最後計算。
    int M = findop(L, R, '+', '-');
    printf("%d\n",findop(L, R, '+', '-'));
    // 找不到低的，再找優先權次低的運算符號。
    if (M == -1)
    {
        M=findop(L, R, '*', '/');
        printf("%d\n",findop(L, R, '*', '/'));
    }




    // 運算符號的左右兩式遞迴下去求得確切數值，然後再計算。
    // Unspecified Behavior：左式、右式，不知先呼叫誰！
    if (M != -1)
    {
        printf("parse goto cal\n");
        return cal(parse(L, M-1), s[M], parse(M+1, R));
    }


    // 括號
    if (s[L] == '(' && s[R] == ')')
    {
        printf("goto Parentheses\n");
        return parse(L+1, R-1);
    }


    // 數值
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

