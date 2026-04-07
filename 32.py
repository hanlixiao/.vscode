#练习                  构建一个第 N 个斐波那契数计算器



def fibonacci(n):
    #必须定义 sequence 列表，初始 [0, 1]
    sequence = [0, 1]

    # 处理特殊情况
    if n == 0:
        return 0
    if n == 1:
        return 1
    
    # 动态规划：从 2 开始计算到 n
    for i in range(2, n + 1):
        next_fib = sequence[i - 1] + sequence[i - 2]
        sequence.append(next_fib)

    return sequence[n]