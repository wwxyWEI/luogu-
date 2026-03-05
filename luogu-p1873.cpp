#include <iostream>
#include<algorithm>

using namespace std;


const int n = 1000010;
int q[n];
int N;
long long M;

bool check(int mid)
{
    long long sum = 0;
    for(int i=0;i<N;i++)
    {
        if(q[i]>mid)sum += q[i]-mid;
    }
    return sum>=M;
}
int main()
{
    scanf("%d%lld",&N,&M);
    for(int i = 0;i<N;i++) cin >> q[i];
    sort(q,q+N);

    
    int l = 0,r = q[N-1];//r不一定要设成下标，也可以像这样设定
    while(l<r)//在高度值域上二分，不同以往的在下标上二分
    {
        int mid = (l+r+1) >> 1;//mid就是锯子的长度
        if(check(mid)){l=mid;}
        else {r=mid-1;}
    }
    printf("%d\n",l);
    return 0;
}