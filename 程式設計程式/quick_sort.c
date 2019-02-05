#include <stdio.h>

void swap(int *a,int *b)
{
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}

int partition_by_key(int A[],int left,int right,int key)
{
    int tleft=left+1;
    int tl=tleft,tr=right;
    swap(&A[key],&A[left]);
    while(tl<=tr)
    {
        while(tl<=tr && A[tl]<=A[left])tl++;
        while(tl<=tr && A[tr]>A[left])tr--;
        if(tl<tr)swap(&A[tl],&A[tr]);
    }
    swap(&A[left],&A[tr]);
    return tr;
}

void quick_sort(int A[], int n)
{
    void recursive_quick_sort(int A[], int left, int right)
    {
        if(left > right) return;
        int key=left;
        key=partition_by_key(A, left, right, key);
        recursive_quick_sort(A, left, key-1);
        recursive_quick_sort(A, key+1, right);
    }
    recursive_quick_sort(A, 0, n-1);
    return;
}


int main()
{
    int a[100],num;
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        scanf("%d",&a[i]);
    }
    quick_sort(a, num);
    for(int i=0;i<num;i++)
    {
        printf("%d ",a[i]);
    }

    return 0;
}
