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

double cross_p (Points f, Points s, Points t)
{
    double vec1[2] = {s.x-f.x, s.y-f.y};
    double vec2[2] = {t.x-f.x, t.y-f.y};
    return vec1[0]*vec2[1] - vec1[1]*vec2[0];
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

    vector<Points> Ans1;
    Ans1.push_back(P[0]);
    Ans1.push_back(P[1]);
    int psize=2;
    for(int i=2; i<P.size();i++)
    {
        while( psize >= 2 && cross_p(Ans1[psize-2],Ans1[psize-1],P[i]) >= 0)
        {

            Ans1.erase(Ans1.begin()+psize-1);
            psize--;
        }
        Ans1.push_back(P[i]);
        psize++;
    }
    cout << endl;
    cout << "find upper hull " << endl;
    for(vector<Points>::iterator iter=Ans1.begin(); iter!=Ans1.end(); ++iter)
        cout << "(" << iter->x << ", " << iter->y << ")" << endl;

    vector<Points> Ans2;
    Ans2.push_back(P[P.size()-1]);
    Ans2.push_back(P[P.size()-2]);
    int psizel=2;
    for(int i=P.size()-3; i>=0;i--)
    {
        while( psizel >= 2 && cross_p(Ans2[psizel-2],Ans2[psizel-1],P[i]) >= 0)
        {
            Ans2.erase(Ans2.begin()+psizel-1);
            psizel--;
        }
        Ans2.push_back(P[i]);
        psizel++;
    }
    cout << endl;
    cout << "find lower hull " << endl;
    for(vector<Points>::iterator iter=Ans2.begin(); iter!=Ans2.end(); ++iter)
        cout << "(" << iter->x << ", " << iter->y << ")" << endl;
    return 0;
}
