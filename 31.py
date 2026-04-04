def dfs_n_queens(n):
    if n < 1:
        return []
    
    result = []

    def dfs(row, cols, diag1, diag2):
        if row == n:
            result.append(cols)
            return
        
        for col in range(n):
            if col not in cols and (row - col) not in diag1 and (row + col) not in diag2:
                dfs(row + 1, cols +[col], diag1 + [row - col], diag2 + [row + col])

    dfs(0, [], [], [])

    return result