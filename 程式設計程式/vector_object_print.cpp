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
void print_point(Points a)
{
    cout << "(" << a.x << ", " << a.y << ")" << endl;
}

int main()
{
    vector <Points> P,F,L;
    int vnum;
    cin >> vnum;
    for(int i=0;i<vnum;i++)
    {
        Points tmp;
        cin >> tmp.x >> tmp.y;
        P.push_back(tmp);
    }
    for(int i=0;i<P.size();i++)
    {
        cout << "x= " <<P[i].x;
        cout << "y= " <<P[i].y << endl;
    }
    sort(P.begin(),P.end(),cmp);

    cout << endl;
    for(int i=0;i<P.size();i++)
    {
        cout << "x= " <<P[i].x;
        cout << "y= " <<P[i].y << endl;
    }
    for_each(P.begin(),P.end(),print_point);
    for(vector<Points>::iterator iter=P.begin(); iter!=P.end(); ++iter)
        cout << "(" << iter->x << ", " << iter->y << ")" << endl;

    return 0;
}
