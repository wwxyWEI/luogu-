 #include <iostream>
#include <algorithm>

using namespace std;

const int N = 20010;

int v,n;
int f[N];

int V[N];

int main()
{
    cin >> v;
    cin >> n;
    for (int i = 0;i < n;i ++)
    {
        cin >> V[i];
    }

    for (int i = 0;i < n;i ++)
        for (int j = v;j >= V[i];j --)
        {
            f[j] = max(f[j],f[j - V[i]] + V[i]);
        }
        
    cout << v - f[v] << endl;
    return 0;
}