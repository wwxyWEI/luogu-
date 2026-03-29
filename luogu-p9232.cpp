#include <iostream>
#include <string>

using namespace std;

int main()
{
    string s;
    int l = 0,r = 0;
    cin >> s;
    int cnt = 0;
    int n = s.size();
    //不需要真的反转，只需要比较第一个不一样的数字，所以只用比较区间两头大小，若s[l]>s[r]，则反转后肯定满足题意，反之不满足
    for (l = 0;l < n;l ++)
    {
        for (r = l + 1;r < n;r ++)
        {
            int i = l,j = r;
            while(i < j&&s[i]==s[j])//有相等的就缩小区间，如果最后i>=j，说明该区间没有合适的，所以此时就跳出内层循环，外层循环变量加一继续循环
            {
                i ++;
                j --;
            }
            if(s[i]>s[j]&&i < j)
            {
                cnt ++;
            }
        }
    }
    cout << cnt;
    return 0;
}