#include <iostream>
#include <algorithm>

using namespace std;

int V,n;
const int M = 21010;

int f[M]; 
int v[M]; 

int main()
{
    cin >> V >> n;

    for (int i = 0;i < n;i ++)
    {
        cin >> v[i]; 
    }
    

    for (int i = 0;i < n;i ++)
        for (int j = V;j >= v[i];j --)
        {
            f[j] = max(f[j],f[j - v[i]] + v[i]); 
        }

    cout << V - f[V]; 
    return 0;
}