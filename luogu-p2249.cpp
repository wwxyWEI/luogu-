#include<iostream>

using namespace std;
const int N = 100000;
int n,m;
int q[N];

int main()
{
    scanf("%d%d",&n,&m);
    for(int i = 1;i<=n;i++) {scanf("%d",&q[i]);}
    while(m--)
    {
        int l = 1,r = n;
        int x;
        scanf("%d",&x);
        while(l<r)
        {
            int mid = l+r >> 1;
            if(q[mid]>=x) {r = mid;}
            else {l = mid + 1;}
        }
        if(q[l]==x){cout << l << " ";}
        else {cout << "-1 "; }
    }cout << endl;/*注意24与25行，把换行放在循环外是因为题目要求输出结果要在同一行
                    如果endl与“-1”放在同一行，可能会导致输出结果不符合要求，从而无法ac
                    所以以后要先测试一下，看看结果是否规范，竞赛对这些要求很严*/                  
    return 0;
}