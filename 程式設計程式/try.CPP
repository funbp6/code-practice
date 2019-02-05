#include <iostream>
#include <random>
#include <fstream>
using namespace std;
int main()
{
    ofstream myfile;
    myfile.open("data.txt");
    std::random_device rd;
    std::default_random_engine gen = std::default_random_engine(rd());
    std::uniform_int_distribution<int> dis(1,100000000);
    int i=0;
    for (i=1; i<=1000000; i++)
    {
        myfile << i <<" 0 " << -dis(gen) << endl;
        myfile << i <<" 1 " << dis(gen) << endl;
    }
    myfile.close();
    return 0;
}
