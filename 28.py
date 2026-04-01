def adjacency_list_to_matrix(adj_list):
    if not adj_list:
        return []
    max_node = max(adj_list.keys())
    n = max_node + 1

    matrix = [[0] * n for _ in range(n)]

    for node in adj_list:
        neighbors = adj_list[node]
        for neighbor in neighbors:
            matrix[node][neighbor] = 1

    for row in matrix:
        print(row)

    return matrix