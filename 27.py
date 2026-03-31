#练习           最短路径问题


#测试用邻接矩阵
INF = float('inf')
adj_matrix = [
    [0, 5, 3, INF, 11, INF],
    [5, 0, 1, INF, INF, 2],
    [3, 1, 0, 1, 5, INF],
    [INF, INF, 1, 0, 9, 3],
    [11, INF, 5, 9, 0, INF],
    [INF, 2, INF, 3, INF, 0],
]

#定义函数
def shortest_path(matrix, start_node, target_node=None):
    #判断矩阵长度
    n = len(matrix)
    #将所有距离设为无穷
    distances = [INF] * n
    #初始节点都本身距离为0
    distances[start_node] = 0
    #路径存储列表
    paths = [[node_no] for node_no in range(n)]
    #用来检查访问的列表初始化为False
    visited = [False] * n

    #遍历所有节点
    for _ in range(n):
        #将最小距离初始化
        min_distance = INF
        #判断是否还有节点
        current = -1
        #遍历寻找最短路径并且还未被访问
        for node_no in range(n):
            if not visited[node_no] and distances[node_no] < min_distance:
                min_distance = distances[node_no]
                current = node_no
        #如果没有可处理的节点推出循环
        if current == -1:
            break
        #将当前节点标记为以访问 确定其最短距离
        visited[current] = True

        #遍历更新距离与路径
        for node_no in range(n):
            #取出当前节点到邻居node_no的距离
            distance = matrix[current][node_no]
            #只有当距离存在且未被访问时再操作
            if distance != INF and not visited[node_no]:
                #计算新路径的距离：起点 → current → node_no
                new_distance = distances[current] + distance
                #如果新路径比当前记录的距离短更新
                if new_distance < distances[node_no]:
                    #更新距离
                    distances[node_no] = new_distance
                    #更新路径
                    paths[node_no] = paths[current] + [node_no]

    #确定要输出的目标节点：如果指定了target_node，就只输出它；否则输出所有节点
    targets = [target_node] if target_node is not None else range(n)
    for node_no in targets:
        #跳过起点本身、以及不可达的节点
        if node_no == start_node or distances[node_no] == INF:
            continue
        #把路径数组转成「0 -> 2 -> 1 -> 5」这样的字符串
        string_path = (str(n) for n in paths[node_no])
        path = ' -> '.join(string_path)
        print(f'\n{start_node}-{node_no} distance: {distances[node_no]}\nPath: {path}')
    
    #返回最短距离和路径
    return distances, paths


#测试
shortest_path(adj_matrix, 0, 5)