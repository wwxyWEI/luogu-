#include<iostream>
#include<algorithm>

using namespace std;

const int N = 2000010;
int n;
int a[N],s[N],q[N];//全局数组自动初始化为0；

int main()
{
    cin >> n;
    int i;
    int sum = 0;

    for(i = 1;i<=n;i++)cin >> a[i];

    for(i = 1;i<=n;i++)s[i]=s[i-1]+a[i];

    int maxsum = -1e9;//初始化最大和为很小的数，因为可能有负数；
     for(int l=1;l<=n;l++)
     {
        for(int r=l;r<=n;r++)
        {
             int sum = s[r]-s[l-1];
             if(sum>maxsum)maxsum=sum;//如果当前子段和大于已知最大值，则更新最大值
        }
    }
   //暴力前缀和枚举，但是会超时；

    cout << maxsum << endl;

    return 0;
}