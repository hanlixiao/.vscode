def validate_isbn(isbn, length):
    # 1. 校验ISBN长度是否符合要求
    if len(isbn) != length:
        print(f'ISBN-{length} code should be {length} digits long.')
        return
    
    try:
        # 2. 分离主数字和校验位（修复一位偏差）
        if length == 10:
            main_digits = isbn[:9]  # ISBN-10主数字是前9位
            given_check_digit = isbn[9]  # 校验位是第10位（索引9）
            
            # 检查主数字是否全为数字（X仅允许在校验位）
            for digit in main_digits:
                if not digit.isdigit():
                    raise ValueError("Invalid character")
            
            # 处理校验位X（仅ISBN-10允许）
            if given_check_digit == 'X':
                pass  # X是合法校验位
            elif not given_check_digit.isdigit():
                raise ValueError("Invalid character")
            
            # 转换主数字为整数列表
            main_digits_list = [int(digit) for digit in main_digits]
        else:  # length == 13
            main_digits = isbn[:12]  # ISBN-13主数字是前12位
            given_check_digit = isbn[12]  # 校验位是第13位（索引12）
            
            # ISBN-13所有字符（包括校验位）必须是数字
            for digit in isbn:
                if not digit.isdigit():
                    raise ValueError("Invalid character")
            
            # 转换主数字为整数列表
            main_digits_list = [int(digit) for digit in main_digits]
        
        # 3. 计算预期校验位
        if length == 10:
            expected_check_digit = calculate_check_digit_10(main_digits_list)
        else:
            expected_check_digit = calculate_check_digit_13(main_digits_list)
        
        # 4. 验证校验位是否匹配
        if given_check_digit == expected_check_digit:
            print('Valid ISBN Code.')
        else:
            print('Invalid ISBN Code.')
    
    except ValueError:
        print('Invalid character was found.')

def calculate_check_digit_10(main_digits_list):
    digits_sum = 0
    for index, digit in enumerate(main_digits_list):
        digits_sum += digit * (10 - index)
    result = 11 - digits_sum % 11
    if result == 11:
        expected_check_digit = '0'
    elif result == 10:
        expected_check_digit = 'X'
    else:
        expected_check_digit = str(result)
    return expected_check_digit

def calculate_check_digit_13(main_digits_list):
    digits_sum = 0
    for index, digit in enumerate(main_digits_list):
        if index % 2 == 0:
            digits_sum += digit * 1
        else:
            digits_sum += digit * 3
    result = 10 - digits_sum % 10
    if result == 10:
        expected_check_digit = '0'
    else:
        expected_check_digit = str(result)
    return expected_check_digit

def main():
    user_input = input('Enter ISBN and length: ')
    values = user_input.split(',')
    
    # 处理：未输入逗号分隔值（IndexError）
    if len(values) != 2:
        print('Enter comma-separated values.')
        return
    
    isbn = values[0].strip()  # 去除首尾空格
    length_str = values[1].strip()
    
    # 处理：长度非数字（ValueError）
    try:
        length = int(length_str)
    except ValueError:
        print('Length must be a number.')
        return
    
    # 校验长度是否为10/13
    if length == 10 or length == 13:
        validate_isbn(isbn, length)
    else:
        print('Length should be 10 or 13.')

# 注释掉main()调用（满足测试1）
# main()