#include <iostream>
#include <random>
#include <fstream>
using namespace std;
int main()
{
    ofstream myfile;
    myfile.open("5.1_data.in.txt");
    std::random_device rd;
    std::default_random_engine gen = std::default_random_engine(rd());
    std::uniform_int_distribution<int> dis(1,100);
    int i=0,j=0;
    myfile << "50" << endl;
    myfile << dis(gen);
    //cout << dis(gen);
    for(j=0;j<49;j++)
    {
        myfile << " " << dis(gen);
        //cout << " " << dis(gen);
    }myfile << endl;
    myfile << dis(gen);
    for(j=0;j<49;j++)
    {
        myfile << " " << dis(gen);
        //cout << " " << dis(gen);
    }
    myfile.close();
    return 0;
}
