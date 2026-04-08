#练习       构建数字模式生成器


#函数
def number_pattern(n):
    #判断传入的n是否为整数
    if not isinstance(n, int):

        return 'Argument must be an integer value.'
    #判断n是否大于1
    if n < 1:

        return 'Argument must be an integer greater than 0.'
    #创建返回列表存放数字
    number = []
    #循环1到n
    for num in range(1, n + 1):
        #将num添加到number列表
        number.append(str(num))
    #返回时在数字之间添加空格
    return ' '.join(number)

#测试
print(number_pattern(4))