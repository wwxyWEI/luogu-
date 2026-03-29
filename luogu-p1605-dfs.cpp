#include <iostream>

using namespace std;

const int K = 10;
int g[K][K];    //1,0分别表示有无障碍,下标表示坐标
bool cnt[K][K]; //是否走过

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};
//移动的方式，上下左右

int res = 0;//记录解法的数量

int n,m,t;
int x,y;//临时的坐标,也用来当作障碍坐标
int sx,sy,fx,fy;

void dfs(int x,int y)
{
    if(x==fx&&y==fy){res++;return;}//找到一种走法
    for(int i=0;i<4;i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<1||nx>n||ny<1||ny>m) continue; //判断是否越界
        if(g[nx][ny]==1) continue;  //遇到障碍
        if(!cnt[nx][ny])
        {
            cnt[nx][ny] = true;
            dfs(nx,ny);
            cnt[nx][ny] = false;
        }
    }
}

int main()
{
    std::cin >> n >> m >> t;
    std::cin >> sx >> sy >> fx >> fy;
    for (int i=0;i<t;i++)
    {
        cin >> x >> y;
        g[x][y] = 1;
    }
    cnt[sx][sy] = true;//保证起点上不会再次经过,以免形成死循环
    dfs(sx,sy);
    std::cout << res;
    return 0;
}