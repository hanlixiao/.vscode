#练习         使用二分法查找数字平方根的函数


#定义函数
def square_root_bisection(square_target, tolerance = 1e-6, max_iterations = 100):
    #判断所求值是否大于0
    if square_target < 0:
        raise ValueError("Square root of negative number is not defined in real numbers")
    
    #如果传入的值为0或1则返回本身
    if square_target == 0 or square_target == 1:
        print(f"The square root of {square_target} is {square_target}")
        return square_target
    
    #设置二分查找的边界  high如果传入值大于1这是本身 如果小于1则为1
    low = 0.0
    high = square_target if square_target > 1 else 1.0

    #二分查找方法
    for _ in range(max_iterations):
        mid = (low + high) / 2
        mid_squared = mid * mid 

        if high - low <= tolerance:
            print(f"The square root of {square_target} is approximately {mid}")
            return mid
        
        if mid_squared < square_target:
            low = mid
        else:
            high = mid

        print(f"Failed to converge within {max_iterations} iterations")
    return None