#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int N,T;

struct gold{
    int m,v;
    double p;//性价比，不在这里初始化，后面再进行计算
}a[110];//定义结构体，存储质量和价值
bool cmp(gold x,gold y)
{
    return x.p>y.p;//用来使得序列从大到小排，优先取走性价比最高的，这也是贪心策略的核心
}

int main()
{
    cin >> N >> T;

    for (int i=1;i<=N;i++) {
        cin >> a[i].m >> a[i].v;
        a[i].p=(double)a[i].v/a[i].m;
    }
    //注意，已经有了结构体，
    //也就是新定义了数据类型，所以要记得用“."";

    sort(a+1,a+N+1,cmp);
    double ans=0;//总价值
    int left=T;//背包剩余空间

    for (int i=1;i<=N;i++)
    {
        //这个if判断的是这部分金币能不能装进来，可以的话就全拿
        if(a[i].m<=left){
            ans += a[i].v;//总价值增加
            left -=a[i].m;//背包空间减少
        }
        //else 这里的代码意思是说这部分金币只能装一部分，而且刚好装满整个背包      
          else {
            ans += a[i].p*left;//直接计算总价值
            break;
        }
    }
    
    cout <<  fixed << setprecision(2) << ans;

    return 0;
}