#include <iostream>
#include <random>
#include <fstream>
using namespace std;
int main()
{
    ofstream myfile;
    myfile.open("5.1_data.txt");
    std::random_device rd;
    std::default_random_engine gen = std::default_random_engine(rd());
    std::uniform_int_distribution<int> dis(1,100);
    int i=0,j=0;
    //cout << "5" << endl;
    myfile << "10" << endl;
    for (i=0; i<10; i++)
    {
        myfile << dis(gen);
        //cout << dis(gen);
        for(j=0;j<9;j++)
        {
            myfile << " " << dis(gen);
            //cout << " " << dis(gen);
        }//cout <<endl;
        myfile << endl;
    }
    myfile << dis(gen);
    //cout << dis(gen);
    for(j=0;j<9;j++)
    {
        myfile << " " << dis(gen);
        //cout << " " << dis(gen);
    }
    myfile.close();
    return 0;
}
