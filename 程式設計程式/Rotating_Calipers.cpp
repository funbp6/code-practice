#include<iostream>
#include<algorithm>
#include<math.h>
#include<vector>

using namespace std;

class Points{public: double x,y;};

bool cmp(Points &a, Points &b)
{
    if(a.x == b.x)
        if(a.y < b.y) return true;
    if(a.x < b.x) return true;
    else return false;
}

double cross_p4 (Points lf, Points ls, Points uf, Points us)
{
    double vec1[2] = {ls.x-lf.x, ls.y-lf.y};
    double vec2[2] = {us.x-us.x, us.y-uf.y};
    return vec1[0]*vec2[1] - vec1[1]*vec2[0];
}

double cross_p (Points f, Points s, Points t)
{
    double vec1[2] = {s.x-f.x, s.y-f.y};
    double vec2[2] = {t.x-f.x, t.y-f.y};
    return vec1[0]*vec2[1] - vec1[1]*vec2[0];
}


double vector_len (Points a, Points b)
{
    double len_x, len_y;
    len_x = (a.x-b.x)*(a.x-b.x);
    len_y = (a.y-b.y)*(a.y-b.y);
    return len_y+len_x;
}

int main()
{
    vector <Points> P;
    int vnum;
    cin >> vnum;
    for(int i=0;i<vnum;i++)
    {
        Points tmp;
        cin >> tmp.x >> tmp.y;
        P.push_back(tmp);
    }
    sort(P.begin(),P.end(),cmp);

    vector<Points> L;
    L.push_back(P[0]);
    L.push_back(P[1]);
    int psize=2;
    for(int i=2; i<P.size();i++)
    {
        while( psize >= 2 && cross_p(L[psize-2],L[psize-1],P[i]) >= 0)
        {

            L.erase(L.begin()+psize-1);
            psize--;
        }
        L.push_back(P[i]);
        psize++;
    }
    cout << endl;
    cout << "find upper hull " << endl;
    for(vector<Points>::iterator iter=L.begin(); iter!=L.end(); ++iter)
        cout << "(" << iter->x << ", " << iter->y << ")" << endl;

    vector<Points> U;
    U.push_back(P[P.size()-1]);
    U.push_back(P[P.size()-2]);
    int psizel=2;
    for(int i=P.size()-3; i>=0;i--)
    {
        while( psizel >= 2 && cross_p(U[psizel-2],U[psizel-1],P[i]) >= 0)
        {
            U.erase(U.begin()+psizel-1);
            psizel--;
        }
        U.push_back(P[i]);
        psizel++;
    }
    cout << endl;
    cout << "find lower hull " << endl;
    for(vector<Points>::iterator iter=U.begin(); iter!=U.end(); ++iter)
        cout << "(" << iter->x << ", " << iter->y << ")" << endl;

    /***************

    Rotating Calipers

    ***************/

    int li=0,ui=0,maxl;
    Points max_up,max_low;
    max_up=U[0];
    max_low=L[0];
    maxl = vector_len(L[0], U[0]);
    cout << "max 0= " << maxl << endl;
    while (li<=L.size()-2 && ui<=U.size()-2  )
    {
        if(li==L.size()-2)
            ui++;
        else if (ui==U.size()-2)
            li++;
        else if (cross_p4(L[li],L[li+1],U[ui],U[ui+1]) > 0)
        {
            li++;
        }
        else
            ui++;
        if(vector_len(L[li], U[ui]) > maxl)
        {
            max_up=U[ui];
            max_low=L[li];
            maxl=vector_len(L[li], U[ui]);
        }

    }
    cout << "last max= " << maxl << endl;
    cout << "last max u= (" << max_up.x << ", " << max_up.y << ")" <<endl;
    cout << "last max l= (" << max_low.x << ", " << max_low.y << ")" <<endl;

    return 0;
}
