#include<iostream>

using namespace std;
int n,p;
const int N = 5e6 + 10;

int a[N],s[N];

int main()
{
    cin >> n >> p;
    for(int i=1;i<=n;i++)
    {
        cin >> s[i];
        a[i]=s[i]-s[i-1];
    }

    while(p--)
    {
        int x,y,z;
        cin >> x >> y >> z;
        a[x]+=z;
        a[y+1]-=z;
    }

    int minx=1e9;//注意，要尽量大点，找最大值就要设置小点；
    for(int i=1;i<=n;i++)
    {
        s[i]=s[i-1]+a[i];
    }
    for(int i=1;i<=n;i++){
        if(s[i]<minx){minx=s[i];}
    }
    cout << minx << endl;
    return 0;
}