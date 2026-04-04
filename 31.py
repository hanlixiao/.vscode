#练习                实现 N-Queens 算法



def dfs_n_queens(n):
    #小于1直接返回空列表
    if n < 1:
        return []
    
    #存放所有解法
    result = []

    #row = 当前处理到第几行
    #cols = 已经放了皇后的列（记录每一行的皇后位置）
    #diag1 = 记录左上→右下对角线（行 -列)
    #diag2 = 记录右上→左下对角线（行 +列)
    def dfs(row, cols, diag1, diag2):
        #递归终止：所有行都放完皇后→找到一个解
        if row == n:
            result.append(cols)
            return
        
        #尝试在当前行的每一列放皇后
        for col in range(n):
            #检查：列、对角线都不能冲突
            if col not in cols and (row - col) not in diag1 and (row + col) not in diag2:
                #继续递归下一行
                dfs(row + 1, cols +[col], diag1 + [row - col], diag2 + [row + col])

    #从第0 行开始搜索
    dfs(0, [], [], [])

    return result