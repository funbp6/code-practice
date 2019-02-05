#include <iostream>
#include <string>
#include <fstream>
#include <sstream>
#include <vector>
#include <algorithm>
#include <unordered_set>

using namespace std;

class Pafline{
public:
    Pafline(string&, int, string&, int, int);
    string readname;
    int readlen;
    string refname;
    int match;
    int alignlen;

};

Pafline::Pafline(string &rn, int rl, string &rfn, int m, int al)
{
    readname = rn;
    readlen = rl;
    refname = rfn;
    match = m;
    alignlen = al;
}

ostream &operator<<(ostream &s, Pafline p)
{
    s << p.readname << " " << p.refname << " " << p.readlen << " " << p.match << " " << p.alignlen;
    return s;
}

void splitstr(string &str)
{
    int pos = str.find_first_of("-");
    str = str.substr(pos+1, str.length() - pos);
    pos = str.find_first_of("_");
    pos = str.find_first_of("_", pos+1);
    str = str.substr(0, pos);
}

void trimfile(ifstream &f, vector<Pafline> &p)
{
    unordered_set<string> uset;
    string line;
    int fileline=0;
    while(getline(f, line))
    {
        string token[12];
        stringstream ss(line);
        for(int i=0;i<12;++i)
        {
            string tmp;
            getline(ss, tmp, '\t');
            token[i] = tmp;
        }
        unordered_set<string>::iterator iter = uset.find(token[0]);
        if(iter==uset.end())
        {
            uset.insert(token[0]);
            splitstr(token[5]);
            Pafline paftmp(token[0], stoi(token[1]), token[5], stoi(token[9]), stoi(token[10]));
            p.push_back(paftmp);
        }
    }
    f.close();
}

void write2file(ofstream &f, vector<Pafline> &p)
{
    f << p[0];
    for(vector<Pafline>::iterator iter=p.begin()+1; iter!=p.end();++iter)
    {
        f << "\n" << *iter;
    }
    f.close();
}


int main()
{
    //string test1 = "name11000+";
    string line;
    vector <Pafline> Spaf;
    ifstream fin("test.txt");
    ofstream of("out.txt");
    trimfile(fin, Spaf);
//    cout << Spaf[0] << endl ;
    write2file(of, Spaf);

    return 0;
}
