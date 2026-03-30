#练习              汉诺塔问题



def hanoi_solver(n):
    #初始化三根柱子A, B, C
    A = list(range(n, 0, -1))
    B = []
    C = []
    steps = []

    #定义保存当前状态的函数
    def save_state():
        steps.append(f"{A} {B} {C}")

    #保存初始状态
    save_state()

    #定义汉诺塔移动递归函数
    def move(n, source, target, auxiliary):
        if n == 0:
            return
        move(n - 1, source, auxiliary, target)

        #移动最上边的函数
        disk = source.pop()
        target.append(disk)
        save_state()

        move(n-1, auxiliary, target, source)

    move(n, A, C, B)

    #将步骤用\n连接并返回
    return "\n".join(steps)