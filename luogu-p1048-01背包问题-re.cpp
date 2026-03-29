#include <iostream>
#include <algorithm>

using namespace std;

int t,m;
const int M = 1010;

int f[M]; //f[i]表示在时间不超过i的情况下，能获得的最大价值
int T[M],w[M]; //T[i]表示第i件物品的时间，w[i]表示第i件物品的价值

int main()
{
    cin >> t >> m;

    for (int i = 0;i < m;i ++)
    {
        cin >> T[i] >> w[i]; 
    }
    
//状态转移方程：f[j] = max(f[j],f[j - T[i]] + w[i])，
//表示在时间不超过j的情况下，能获得的最大价值要么是之前的f[j]，
//要么是f[j - T[i]] + w[i]，即在时间不超过j - T[i]的情况下，
//能获得的最大价值加上第i件物品的价值w[i]

    for (int i = 0;i < m;i ++)
        for (int j = t;j >= T[i];j --)
        {
            f[j] = max(f[j],f[j - T[i]] + w[i]); 
        }

    cout << f[t]; //输出在时间不超过t的情况下，能获得的最大价值
    return 0;
}