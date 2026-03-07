#include <iostream>
#include <algorithm>
#include <iomanip>

using namespace std;

int w,n;

struct grp{
    int per; 
}a[30010];
//其实没必要用结构体，因为变量只有一个
bool cmp(grp x,grp y)
{
    return x.per < y.per; //这个其实也没有必要，因为默认是升序的
}

int main()
{
    cin >> w >> n;
    for (int i=1;i<=n;i++)
    {
        cin >> a[i].per;
    }

    sort(a+1,a+n+1,cmp);
    
    int res = 0;
    int left = w;//这个也有点多余
    int i=1,j=n;

    while(i<=j)//不是i<j,因为当只剩下一个时也要装
    {
        if(a[i].per + a[j].per <=left)
        {
            res++;
            i++;
            j--;
        }
        else {   //只装最贵的
            j--;
            res++;
        }
    }
    cout << res;
    return 0;
}
//双指针，最贵的与最便宜的配对，不能配对则单独装贵的