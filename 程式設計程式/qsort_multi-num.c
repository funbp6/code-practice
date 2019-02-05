#include<stdio.h>
#include<stdlib.h>

int cmp(const void *a, const void *b)
{
    return *(int*)a - *(int*)b;
}

int cmp_2(const void *a, const void *b)
{
    if(*(int*)a == *(int*)b)
    {

        int *c=(int*)a+2;
        int *d=(int*)b+2;
        return *d - *c;
    }
    return *(int*)a - *(int*)b;
}

int main()
{
    int sort_n, qsort_array[100000][3];
    scanf("%d", &sort_n);
    for(int i=0;i<sort_n;i++)
    {
        scanf("%d %d %d", &qsort_array[i][0], &qsort_array[i][1], &qsort_array[i][2]);
    }
    for(int i=0;i<sort_n;i++)
    {
        printf("number %d = %d,%d,%d\n", i, qsort_array[i][0], qsort_array[i][1], qsort_array[i][2]);
    }
    printf("\n");
    qsort(qsort_array, sort_n, sizeof(int)*3, cmp);

    printf("sort by column 1\n");
    for(int i=0;i<sort_n;i++)
    {
        printf("number %d = %d,%d,%d\n", i, qsort_array[i][0], qsort_array[i][1], qsort_array[i][2]);
    }
    printf("\n");
    qsort(qsort_array, sort_n, sizeof(int)*3, cmp_2);

    printf("sort by column 1, 3\n");
    for(int i=0;i<sort_n;i++)
    {
        printf("number %d = %d,%d,%d\n", i, qsort_array[i][0], qsort_array[i][1], qsort_array[i][2]);
    }

    return 0;
}
