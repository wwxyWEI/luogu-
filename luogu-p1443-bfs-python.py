from collections import deque #引入双端队列，BFS 需要使用队列来存储待访问的节点
#和c++的queue不同，python的deque可以在两端进行高效的插入和删除操作，非常适合实现 BFS。

n,m,sx,sy = map(int,input().split())#输入棋盘的行数、列数以及起点的坐标

#Python索引表从0开始，所以后面sx-1，sy-1 来调整为0基索引

dist = [[-1]*m for _ in range(n)] #创建一个二维列表来记录每个位置到起点的最短距离，初始值为 -1 表示未访问过
#dist[i][j] 表示从起点到位置 (i,j) 的最短距离.
#初始化为-1，类似c++中的 memset(dist,-1,sizeof dist)

dx = [-2,-2,2,2,-1,-1,1,1] #定义八个方向的移动，分别对应骑士在棋盘上的八种可能的移动方式
dy = [-1,1,-1,1,-2,2,-2,2]


#bfs 主逻辑：
dist[sx-1][sy-1] = 0 #将起点的距离设置为 0，表示从起点到起点的距离为 0
q = deque() #创建一个双端队列来存储待访问的节点
q.append((sx-1,sy-1)) #将起点坐标入队，开始 BFS 的过程，从起点开始访问

while q: #当队列不为空时，继续进行 BFS
    x,y = q.popleft() 
#这里相当于c++中的 auto cur = q.front(); q.pop(); 取出队头元素，并将其从队列中移除，cur 是一个 pair，包含当前访问的位置的坐标 (x,y)
    for i in range(8): #8种方向都试一遍
        nx = x + dx[i] #计算下一个位置的坐标
        ny = y + dy[i]
        #判断是否越界
        if nx < 0 or nx >= n or ny < 0 or ny >= m:
            continue #如果下一个位置超出棋盘范围，跳过这个位置
        if dist[nx][ny] !=-1:
            continue #如果下一个位置已经访问过，跳过这个位置
        dist[nx][ny] = dist[x][y] + 1 #更新下一个位置的距离，等于当前位置的距离加 1
        q.append((nx,ny)) #这里相当于c++中的 q.push({nx,ny}); 将下一个位置入队，继续 BFS 的过程


for i in range(n):
    for j in range(m):
        print(dist[i][j],end = ' ') #输出每个位置到起点的最短距离，使用空格分隔
    print() #每行结束后换行
            #牛逼