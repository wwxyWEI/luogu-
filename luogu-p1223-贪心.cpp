#include<iostream>
#include<algorithm>

using namespace std;
const int N = 1e3 + 10;

int t[N];
int n;

int main()
{
    cin >> n;
    for (int i=1;i<=n;i++) cin >> t[i];
    sort(t+1,t+n+1);
    
    long long total = 0;
    for(int i=1;i<=n;i++) total+=t[i]*(n-i);

    float m=total/n;
    printf("%2f",m);
    return 0;
}