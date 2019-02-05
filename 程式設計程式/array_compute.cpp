#include <iostream>

using namespace std;

int main()
{
    int n,a[100],c[100];
    cin >> n;
    for (int i=0;i<n;i++)
    {
        cin >> a[i];
    }
    for (int i=0;i<n;i++)
    {
        cin >> c[i];
    }
    int ans=0;
    for (int i=0;i<n;i++)
    {
        ans+=a[i]*c[i];
    }
    cout << ans << endl;
    return 0;
}
