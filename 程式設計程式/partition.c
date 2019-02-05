#include <stdio.h>

void swap(int *a,int *b)
{
    int tmp;
    tmp=*a;
    *a=*b;
    *b=tmp;
}

void partition(int left,int right,int a[],int pivot)
{
    int tleft=left+1;
    int tl=tleft,tr=right;
    swap(&a[pivot],&a[left]);
    while(tl<=tr)
    {
        while(tl<=tr && a[tl]<=a[left])tl++;
        while(tl<=tr && a[tr]>a[left])tr--;
        if(tl<tr)swap(&a[tl],&a[tr]);
    }
    swap(&a[left],&a[tr]);

}

int main()
{
    int a[100],num;
    scanf("%d",&num);
    for(int i=0;i<num;i++)
    {
        scanf("%d",&a[i]);
    }
    partition(0,5,a,3);
    for(int i=0;i<num;i++)
    {
        printf("%d ",a[i]);
    }

    return 0;
}
