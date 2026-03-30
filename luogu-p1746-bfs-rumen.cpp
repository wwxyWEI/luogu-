#include <iostream>
#include <cstring>
#include <queue>

using namespace std;

const int N = 1010;

int dx[] = {1,-1,0,0};
int dy[] = {0,0,1,-1};

int n,sx,sy,fx,fy;

int dist[N][N];//记录是否来过这个位置,并记录步数
char g[N][N]; //地图

int bfs()
{
    queue<pair<int,int>> q;
    memset (dist,-1,sizeof dist);
    q.push({sx,sy});

    dist[sx][sy] = 0;
    while(!q.empty()){
        auto cur = q.front();q.pop();
        int x = cur.first;
        int y = cur.second;
        if (x == fx&&y == fy) return dist[x][y];
        for (int i = 0;i < 4;i ++)
        {
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<1||nx>n||ny<1||ny>n) continue;
            if(dist[nx][ny] != -1) continue;
            if(g[nx][ny] == '1') continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx,ny});
        }
    }
    return -1;
}

int main()
{
    cin >> n;
    for (int i = 1;i <= n;i ++)
        cin >> (g[i]+1);

    cin >> sx >> sy >> fx >> fy;

    cout << bfs() << endl;
    return 0;
}