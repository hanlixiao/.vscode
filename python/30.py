#练习        深度优先搜索算法练习



def dfs(graph, start):
    #定义访问列表 记录访问过的数据
    visited = []
    #将初始七点放入栈中
    stack = [start]

    #循环只要栈不为空就还有路径可走
    while stack:
        #取出栈顶元素
        node = stack.pop()
        #如果访问过直接跳过
        if node not in visited:
            #未访问添加到访问过的列表
            visited.append(node)
            #寻找相邻的节点
            for neighbor, connected in enumerate(graph[node]):
                #找到时添加到栈中
                if connected == 1:
                    if neighbor not in visited:
                        stack.append(neighbor)

    #返回列表
    return visited