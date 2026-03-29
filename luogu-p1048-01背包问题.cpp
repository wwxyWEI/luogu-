#include <iostream>

using namespace std;
const int N = 1010;
int f[N];
int main()
{
    int T,M;
    cin >> T >> M;
    for(int i = 0;i < M;i++)
    {
        int t,v;
        cin >> t >> v;
        for(int j = T;j >= t;j--)
        {
            f[j] = max(f[j],f[j-t]+v);
        }
    }
    int ans = 0;
    for(int i = 0;i <= T;i++)
    {
        ans = max(ans,f[i]);
    }
    cout << ans << endl;
    return 0;
}