#include<iostream>
#include<algorithm>
#include<math.h>

using namespace std;

double vangle(pair<double,double>f, pair<double,double>s)
{
    double lenfs,lenos;
    lenfs=sqrt(f.first*f.first+f.second*f.second);
    lenos=sqrt(s.first*s.first+s.second*s.second);
    cout << "lenfs= " << lenfs << " " << "lenos= " << lenos << endl;
    if (lenfs==0 || lenos==0) return 10000;
    else return acos((f.first*s.first+f.second*s.second)/(lenfs*lenos));
}

int main()
{
    int vnum,bigx=0;
    pair <double,double> v[10000],bigv;
    cin >> vnum;
    for(int i=0;i<vnum;i++)
    {
        cin >> v[i].first >> v[i].second;
        if(v[i].first > bigv.first)
        {
            bigx=i;
            bigv=v[i];
        }
    }
    pair <double,double> bigvector,Vi,Ni=bigv,Vnow(0.0,1.0),ans[10000];
    ans[0]=bigv;

    int r=1;
    do
    {
        cout << "round " << r << endl;
        cout <<endl;
        pair <double,double> rbigVi,rbigNi;
        double smallcos=100;
        for(int i=0;i<vnum;i++)
        {
            double va,bv;
            Vi.first = v[i].first - Ni.first;
            Vi.second = v[i].second - Ni.second;
            cout << "The" << i <<"'th Node=  (" << v[i].first << " " << v[i].second  << "}" << endl;
            va = vangle(Vi,Vnow);
            cout << "vectors angle= " << va*180/3.1415 <<endl;
            if(smallcos > va)
            {
                smallcos = va;
                rbigVi=Vi;
                rbigNi=v[i];
            }
            cout <<endl;
        }
        Vnow=rbigVi;
        Ni=rbigNi;
        cout << "Next node=  (" << Ni.first << " " << Ni.second << ")" << endl;
        cout <<endl;
        ans[r]=rbigNi;
        r++;

    }while(Ni!= bigv);
    cout << endl;
    for(int k=0;k<r;k++)
    {
        cout << "ANS node => " << ans[k].first << " " << ans[k].second << endl;
    }

    return 0;
}




