#include<stdio.h>

    int n;        //要排列的数字个数
    int ans[10];  //存放当前排列（最多9个数）
    int used[10] = {0};   //标记数字是否用过，0表示未用，1表示已用

    void dfs(int step)   //step 表示当前正在填第几个位置（从0开始）
    {
        int i;
        if(step==n){  //已经填满了n个位置 》》输出一个排列；
            for(i=0;i<n;i++)
            {
                printf("%5d",ans[i]);
            }
                printf("\n");
                return;    //回溯到调用它的那一层,表示已经试完一种可能了；
        }
        for(i=1;i<=n;i++){
        if(!used[i])
        {
            used[i]=1;     //标记，表示该数字已使用；
            ans[step]=i;   //放入数字；
            dfs(step+1);   //每次调用完后都会返回到上一层调用它的函数中；
            used[i]=0;     //回溯标记，使之后的程序可以继续递归；
        }
    }
    }
int main()
{
    scanf("%d",&n);
    dfs(0);  //从第0个位置开始填；
    return 0;
}
