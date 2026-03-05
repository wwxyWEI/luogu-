#include<stdio.h>
#include<math.h>
#include<string.h>


int Pisem(int n);
int main()
{
    char str[101];
    int cnt[26] = {0};
    scanf("%s",str);
    
    int i,len;
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
            if(cnt[i]>maxn){maxn = cnt[i];}
            if(cnt[i]<minn){minn = cnt[i];}
        }
    }
       
        int gap = maxn - minn;
    
        if(Pisem(gap))
        {printf("Lucky Word\n%d\n",gap);}
        else{printf("No Answer\n0\n");}
    
    return 0;
}
int Pisem(int n)
{
    if(n==2){return 1;}
    if(n%2==0){return 0;}
    if(n<2){return 0;}

    int i;
    for(i = 3;i<=sqrt(n);i+=2)
    {
        if(n%i==0)
        {
            return 0;
        }
    }
    return 1;
}