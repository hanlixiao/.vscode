#练习              Luhn算法练习


#定义函数
def verify_card_number(card_number):
    #将传入字符串中的‘-’和空格剔除
    cleaned = card_number.replace('-', '').replace(' ', '')

    #将字符串转化为int类型的列表
    digits = [int(c) for c in cleaned]

    #计算总和
    total = 0

    #从倒数第二个开始各一个遍历 并加倍 如果为两位数则将两位数相加 最后加到total中
    for i in range(len(digits) - 2, -1, -2):
        doubled = digits[i] * 2

        if doubled > 9:
            doubled -= 9
        total += doubled

    #将其余数字加到total中
    for i in range(len(digits) - 1, -1, -2):
        total += digits[i]

    #判断是否符合
    if total % 10 == 0:
        return 'VALID'
    else:
        return 'INVALID'