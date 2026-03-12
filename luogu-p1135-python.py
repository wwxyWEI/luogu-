from collections import deque

n,a,b = map(int,input().split())

dist = [-1]*(n+1) #创建一个一维列表
dist[a] = 0 #让起点初始值为0，其他为-1，这样dist[cur] + 1才能真正发挥作用
dk = []
dk = list(map(int,input().split())) #dk的输入必须在bfs之前，因为bfs需要用到dk数组，如果dk的输入在bfs之后，那么在bfs中访问dk[cur-1]时就会出错，因为dk数组还没有被赋值，所以必须先输入dk数组，然后再调用bfs函数，这样在bfs函数中访问dk[cur-1]时才不会出错
                                    #而且python是顺序执行，没有函数前置说明
q =deque()
q.append(a)

while q:
    cur = q.popleft()  
    up = cur + dk[cur - 1]
    down = cur - dk[cur - 1] #因为python是从0开始索引的，所以的cur-1是索引

    if up<=n and dist[up] == -1:
        dist[up] = dist[cur] + 1 #这里的cur是楼层
        q.append(up)
    if down>=1 and dist[down] == -1:
        dist[down] = dist[cur] + 1
        q.append(down)


print(dist[b])

