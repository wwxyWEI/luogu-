#include <stdio.h>
#include <math.h>
#include <string.h>
int zhishu(int a);
int main()
{
    char str[101];
    int j,i = 0;
    scanf("%s",str);    
  

    int cnt[26] = {0};
    int count,len;
    len = strlen(str);
    
    for(i = 0;i<len;i++)
    {
      cnt[str[i] - 'a']++;
    }
    int maxn = 0,minn = 1000;
    for(i = 0;i<26;i++)
    {
        if(cnt[i]>0)
    {
        if(cnt[i]>maxn)
        {maxn = cnt[i];}
        if(cnt[i]<minn)
        {minn = cnt[i];}
    }
    }

    int cha = maxn - minn;
    if(zhishu(cha))
    {
        printf("Lucky Word\n");
        printf("%d",cha);
    }
    else{
        printf("No Answer\n");
        printf("0");
    }
    
    return 0;
}
int zhishu(int a)
{
    int i;
    if(a<2)return 0;
    if(a==2)return 1;
    if(a%2==0)return 0;
    for(i = 3;i<=sqrt(a);i+=2)
    {
        if(a%i==0)
        {return 0;}
    }
    return 1;
}