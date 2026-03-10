#include <iostream>
#include <queue>
#include <cstring>

using namespace std;

int dx[] = {-2,-2,2,2,-1,-1,1,1};
int dy[] = {-1,1,-1,1,-2,2,-2,2};
//题目要求输出每个位置到起点的最短距离，使用 BFS 来求解，BFS 的核心思想是层次遍历，
//题目要求输出每个位置到起点的最短距离，使用 BFS 来求解，BFS 的核心思想是层次遍历，
const int N = 410;
int dist[N][N]; //记录步数
int n,m,sx,sy;

void bfs(int sx,int sy){
    queue<pair<int,int>> q; //创造队列
    memset(dist,-1,sizeof dist); //全都初始化为-1，表示未访问过
    q.push({sx,sy});
    dist[sx][sy] = 0;
    
    while(!q.empty())
    {
        auto cur = q.front();q.pop();
        int x = cur.first;
        int y = cur.second;

        for (int i = 0;i<8;i++)
        { 
            int nx = x + dx[i];
            int ny = y + dy[i];
            if(nx<1||nx>n||ny<1||ny>m) continue;
            if(dist[nx][ny] != -1) continue;
            dist[nx][ny] = dist[x][y] + 1;
            q.push({nx,ny});
            
        }
    }
}
int main()
{
    cin >> n >> m >> sx >> sy;
    bfs(sx,sy);
    for (int i = 1;i<=n;i++)
    {
        for (int j = 1;j<=m;j++)
        {
            cout << dist[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}

