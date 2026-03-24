



def square_root_bisection(square_target, tolerance = 1e-6, max_iterations = 100):
    if square_target < 0:
        raise ValueError("Square root of negative number is not defined in real numbers")
    
    if square_target == 0 or square_target == 1:
        print(f"The square root of {square_target} is {square_target}")
        return square_target
    
    low = 0.0
    high = square_target if square_target > 1 else 1.0

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