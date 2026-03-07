#include <iostream>
#include <cstring>
using namespace std;
//注意，括号的嵌套不止一层，所以不能单纯的用0，1标记来判断
//用计数器思想，zhai的思想
//计数器模拟zhai，深度 cnt 记录未匹配的左括号数
const int N = 260;
int main()
{
    string a;
    cin >> a;
    int cnt = 0;
    
    for (int i=0;i<a.size();i++)
    {
        if(a[i]=='(') {cnt ++;} //正常判断
        else if(a[i]==')')
        {
            cnt --;
            if(cnt<0) //这是右边括号多于左边的情况
            {
                cout << "NO" << endl;
                return 0;  //可以直接判断不正确，返回值
            }
        }
        else if(a[i]=='@'){break;} //能到这只能说明右括号多于左括号的情况不存在
    }
    if(cnt==0){cout << "YES" << endl;}//这里的判断是为了检查左括号是否过多
    else {cout << "NO" << endl;}

    return 0;
}