#include<stdio.h>

int n;
int ans[10];
int used[10] = {0};

void dfs(int step)
{
    int i;
    if(step==n)
    {
        for(i = 0;i<n;i++)
        {
            printf("%5d",ans[i]);
        }
            printf("\n");
        return;
    }

    
    for(i = 1;i<=n;i++)
    {
        if(!used[i])
        {
            used[i] = 1;
            ans[step] = i;
            dfs(step+1);
            used[i] = 0;
        }
    }
}

int main()
{
    scanf("%d",&n);
    dfs(0);
    return 0;
}