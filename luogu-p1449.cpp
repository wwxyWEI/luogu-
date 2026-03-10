#include <iostream>
#include <cstring>
#include <stack>//虽然题目要求使用数组模拟栈，但这里我们可以直接使用C++ STL中的stack来简化代码，提升可读性和维护性

using namespace std;

const int N = 60;

int main()
{
    string s;  //输入的表达式，可能包含数字、运算符和结束符@
    cin >> s;
    int stk[10000];
    int top = 0;//模拟栈，top表示栈顶位置，stk数组用来存储栈中的元素
    //遇到"."分隔符时，什么操作都不做，继续读取下一个字符
    for (int i=0;i<s.size();i++)
    {
        char ch = s[i];//当前字符
        if (s[i]>='0' && s[i]<='9')
    {
        int num = 0;
        while(s[i]>='0' && s[i]<='9')//(也是为了防止有多位数如123)如果当前字符是数字，就继续读取，直到遇到非数字字符为止
        {
            num = num*10 + (s[i]-'0');
            i++;//继续读取数字，直到遇到非数字字符
        }
        stk[++top] = num;//入栈
        i--;
        //while循环结束后，i已经指向了下一个非数字字符的位置，所以需要i--来回退到当前数字的最后一位，以便下一次循环能够正确处理下一个字符
        //因为for循环会i++，所以这里需要i--来抵消一下，回退1，否则可能会跳过一个字符，导致错误的结果
    }
    else if(ch=='+' || ch=='-' || ch=='*' || ch=='/')
    {
        //当遇到运算符时，需要从栈中弹出两个操作数进行运算
        //想像一下栈的结构，后缀表达式中操作数是先入栈的，所以在遇到运算符时，先弹出的操作数是第二个操作数，后弹出的操作数是第一个操作数
        int b=stk[top--];//弹出栈顶元素，作为运算的第二个操作数
        int a=stk[top--];//弹出栈顶元素，作为运算的第一个操作数
        int res;//存储运算结果

        if(ch=='+'){res=a+b;}
        else if(ch=='-'){res=a-b;}
        else if(ch=='*'){res=a*b;}
        else if(ch=='/'){res=a/b;}
        
        stk[++top]=res;//将运算结果入栈，准备进行下一步运算
    }
    else if (ch=='@'){break;} //遇到结束符@，表示表达式结束，跳出循环，准备输出结果
    }
    std::cout << stk[top] << std::endl;
    return 0;
}