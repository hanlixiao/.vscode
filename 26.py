def hanoi_solver(n):
    A = list(range(n, 0, -1))
    B = []
    C = []
    steps = []

    def save_state():
        steps.append(f"{A} {B} {C}")

    save_state()

    def move(n, source, target, auxiliary):
        if n == 0:
            return
        move(n - 1, source, auxiliary, target)

        disk = source.pop()
        target.append(disk)
        save_state()

        move(n-1, auxiliary, target, source)

    move(n, A, C, B)

    return "\n".join(steps)