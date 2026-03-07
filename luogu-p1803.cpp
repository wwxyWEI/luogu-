#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

const int N = 10e8 + 10;

int n;//参加比赛的数目

struct race{
    int l,r;
}a[100010];

bool cmp(race x,race y)
{
    return x.r<y.r;//右端点从小到大升序
}

int main()
{
    cin >> n;
    for (int i=0;i<n;i++)
    {
        cin >> a[i].l >> a[i].r;
    }
    sort(a,a+n,cmp);

     
    int res = 0;
    int ed = 2e-9;//设置左端点，初始化要尽量小点
    for (int i=0;i<n;i++)
    {
        if(a[i].l>=ed)
        {
            res++;
            ed = a[i].r;
        }
    }

    cout << res;

    return 0;
}
//按右端点排序，尽可能选取早结束的比赛/区间，和905类似，但这里选的是区间数量