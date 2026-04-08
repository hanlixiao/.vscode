#练习       解密诗句


#解密函数  可以同时解密多个诗
def pin_extractor(poems):

    #创建一个新的密码列表
    secret_codes = []

    #循环每一首诗
    for poem in poems:

        #创建空密码
        secret_code = ''
        #将密码以行分开
        lines = poem.split('\n')
        #使用enumeratr函数获取行索引
        for line_index, line in enumerate(lines):
            #将每一行拆分
            words = line.split()
            #判断是否符合要求
            if len(words) > line_index:

                secret_code += str(len(words[line_index]))

            #不符合将以0代替
            else:

                secret_code += '0'
        #将密码添加到密码列表        
        secret_codes.append(secret_code)
    #返回密码列表
    return secret_codes    


#测试
poem = """Stars and the moon
shine in the sky
white and
until the end of the night"""

poem2 = 'The grass is green\nhere and there\nhoping for rain\nbefore it turns yellow'
poem3 = 'There\nonce\nwas\na\ndragon'

print(pin_extractor([poem, poem2, poem3]))
