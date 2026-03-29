#include <iostream>

using namespace std;

int x,y;
int n,m,t;
int sx,sy,fx,fy;
const int N = 20;
int res = 0;

int dx[] = {1, -1, 0, 0};
int dy[] = {0, 0, 1, -1};

int g[N][N];
bool vis[N][N];

void dfs(int x,int y)
{
    if(x == fx&&y == fy){
        res ++;
        return;
    }

    for (int i=0;i<4;i++)
    {
        int nx = x + dx[i];
        int ny = y + dy[i];
        if(nx<1||nx>n||ny<1||ny>m) continue;
        if(g[nx][ny] == 1) continue;
        if(!vis[nx][ny])
        {
            vis[nx][ny] = true;
            dfs(nx,ny);
            vis[nx][ny] = false;
        }
    }
}

int main()
{
    cin >> n >> m >> t;
    cin >> sx >> sy >> fx >> fy;
    for (int i=0;i<t;i++)
    {
        cin >> x >> y;
        g[x][y] = 1;
    }
    vis[sx][sy] = true;
    dfs(sx,sy);
    cout << res;
    return 0;
}