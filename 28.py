#练习               邻接列表到矩阵的转换器


#转换函数
def adjacency_list_to_matrix(adj_list):
    #如果为空列表返回空
    if not adj_list:
        return []
    #计算有几个节点
    max_node = max(adj_list.keys())
    n = max_node + 1

    #创建空矩阵
    matrix = [[0] * n for _ in range(n)]

    #循环遍历查看是否可以连接可以则改为1
    for node in adj_list:
        neighbors = adj_list[node]
        for neighbor in neighbors:
            matrix[node][neighbor] = 1

    #打印
    for row in matrix:
        print(row)

    #返回
    return matrix