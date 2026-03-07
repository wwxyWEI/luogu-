#include <iostream>

using namespace std;
const int N = 200;
int stk[N];

int main()
{
    int i = 1;
    int n,m;
    cin >> n >> m;
    int hh = 1,tt = 0;

    int j = 0;
    while (n--)
    {
        j += 1;
        stk[++ tt] = i;
        i += 1;
        if(j==3)
        {
            hh ++;//弹出
            stk[hh ++] = i;
            cout << i-1 << " ";
            int j = 0; 
        }
    }
    return 0;
}
//错误示范