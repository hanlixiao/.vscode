def dfs(graph, start):
    visited = []
    stack = [start]
    while stack:
        node = stack.pop()
        if node not in visited:
            visited.append(node)
            for neighbor, connected in enumerate(graph[node]):
                if connected == 1:
                    if neighbor not in visited:
                        stack.append(neighbor)

    return visited