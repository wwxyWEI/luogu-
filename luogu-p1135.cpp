#include <iostream>
#include <queue>
#include <cstring>

using namespace std;
const int N = 210;
int dist[N]; //记录次数

int dk[N] = {}; //记录电梯的操作，上或者下多少层
int n,a,b;



void bfs(int n,int ax,int bx,int dk[])
{
    memset(dist,-1,sizeof dist);    
    queue<int> q;
    q.push(ax);
    //记录次数，初始位置的次数为0，其他位置的次数为-1，表示未访问过
    dist[ax] = 0;//刚刚没注意到这个细节，之前没加上这个
    
    while(!q.empty())
    {
        int cur = q.front();q.pop(); //cur是当前所在的楼层
        int up = cur + dk[cur-1]; //cur，楼层是从1开始的，而数组是从0开始的，所以要cur-1
        int down = cur - dk[cur-1];

        if(up<=n && dist[up] == -1)
        {
            dist[up] = dist[cur] + 1;
            q.push(up); 
        }
        if(down>=1 && dist[down] == -1)
        {
            dist[down] = dist[cur] + 1;
            q.push(down);
        }//上和下是独立的，所以不能用else if，之前写成else if了，导致有些情况没考虑到，比如上和下都可以走的情况，之前写成else if了，就只能走上或者下其中一个了，导致结果不对
    }    //也就是说，可能上和下都可以走的情况，如果写成else if，就只能走上或者下其中一个了，导致结果不对，所以要分开写，不能用else if
}

int main()
{
    cin >> n >> a >> b;
    for(int i=0;i<n;i++)
    { cin >> dk[i]; }

    bfs(n,a,b,dk);
    cout << dist[b];
    
    return 0;
}