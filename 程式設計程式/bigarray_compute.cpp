#include <iostream>

using namespace std;

int main()
{
    int **marr,n,*varr;
    cin >> n;
    varr=new int[n];
    marr=new int *[n];
    for(int i=0;i<n;i++)
    {
        marr[i]=new int[n];
    }
    int k,j;
    for(k=0;k<n;k++)
    {
        for(j=0;j<n;j++)
        {
            cin >> marr[j][k];
        }
    }
    for(int i=0;i<n;i++)
    {
        cin >> varr[i];
    }
    int kk,jj,*presum;
    presum=new int [n]();

    for(kk=0;kk<n;kk++)
    {
        for(jj=0;jj<n;jj++)
        {
            //cout << "pre=" << presum[kk] << ", varr=" << varr[jj] << ", marr=" << marr[kk][jj] << endl;
            presum[kk]+=varr[jj]*marr[kk][jj];
        }
    }
    for(int i=0;i<n;i++)
    {
        //cout << presum[i] << endl;
    }
    int k2,j2,fsum=0;
    for(k2=0;k2<n;k2++)
    {
        //cout << "presum=" << presum[k2] << ", varr=" << varr[k2] << endl;
        fsum+=presum[k2]*varr[k2];
    }
    cout << fsum << endl;




    for(int i=0;i<n;i++)
    {
        delete[] marr[i];
    }delete[] marr;
    delete[]varr;

    return 0;
}
