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

double dot_p (Points u, Points P)
{
    return u.x*P.x + u.y*P.y;
}

bool dir_by_dot (Points u, Points l , Points r)
{
    Points V;
    V.x = l.x - r.x;
    V.y = l.y - r.y;
    if(dot_p(u,V)>0)
        return true;
    return false;
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

    for(vector<Points>::iterator i = P.begin();i != P.end();++i)
    {
        cout << "Points " << i-P.begin() << " = " << i->x << ", " << i->y << endl;
    }
    cout << endl;

    // input query vector

    Points query_vector;
    while( cin >> query_vector.x >> query_vector.y)
    {
        Points BS_Left,BS_Right;
        int left=0, right=vnum-1, mid;
        int upleft, upright;
        BS_Left.x = P[1].x - P[0].x;
        BS_Left.y = P[1].y - P[0].y;
        if(dot_p(query_vector, BS_Left)>0) upleft=1;
        if(upleft==0 && dir_by_dot(query_vector, P[vnum-1], P[0])==0)
        {
            cout << "Ans = " << "( " << P[0].x << ", " << P[0].y << " )" << endl;
            return 0;
        }
    }



    return 0;
}
