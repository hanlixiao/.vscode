T = int(input())
for _ in range(T):
    n = int(input())
    students = []
    for _ in range(n):
        s, d, t = input().split()
        d = int(d)
        t = int(t)
        students.append((s, d, t))

    students.sort(key = lambda x: (-x[1], -x[2], x[0]))

    rank = 1
    pre_d, pre_t = students[0][1], students[0][2]
    students[0] = (students[0][0], students[0][1], students[0][2], rank)
    for i in range(1, n):
        cur_d, cur_t = students[i][1], students[i][2]
        if cur_d == pre_d and cur_t == pre_t:
            now_rank = rank
        else:
            now_rank = i + 1
            rank = now_rank
            pre_d = cur_d 
            pre_t = cur_t
        students[i] = (students[i][0], students[i][1], students[i][2], now_rank)

    for stu in students:
        print(f"{stu[3]} {stu[0]} {stu[1]} {stu[2]}")