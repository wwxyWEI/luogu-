#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

const int N = 2e8 + 10;
int n,m;


struct fen{
    int o,r;//o 是单价，r 是最多卖出量；
    int money;
}a[20000000];

bool cmp(fen x,fen y)
{
    return x.o < y.o; //按单价升序
}

int main()
{
    cin >> n >> m;
    for (int i=1;i<=m;i++)
    {
        cin >> a[i].o >> a[i].r;
        a[i].money = a[i].o*a[i].r;
    }
    
   sort(a+1,a+m+1,cmp);//排序，注意这里是m不是n，我就是因为这个找了半天bug

   
   int left = n;//还剩下多少要买

   int ans = 0;//总费用
   for (int i=1;i<=m;i++)
   {
    if(a[i].r<=left){   //能够全买
        left -= a[i].r;
        ans += a[i].money;
    }
    else {   //只能买一部分
        ans += a[i].o*left;
        break;//买够了，所以直接退出循环
    }
   }

   cout << ans;
    return 0;
}