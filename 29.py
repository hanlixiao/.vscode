#练习             BFS 广度优先搜索



def gen_parentheses(pairs):
    #判断输入数据是否合法
    if not isinstance(pairs, int):
        return 'The number of pairs should be an integer'
    if pairs < 1:
        return 'The number of pairs should be at least 1'
    
    #定义初始列表
    queue = [('', 0, 0)]
    #返回时存储列表
    result = []
    #循环主体
    while queue:
        #将队列头弹出一位 
        #current为当前括号 opens_used为左括号 closes_used为右括号
        current, opens_used, closes_used = queue.pop(0)
        #如果括号长度达到要求择添加到result中
        if len(current) == 2 * pairs:
            result.append(current)
        else:
            #如果左括号少于要求则添加
            if opens_used < pairs:
                queue.append((current + '(', opens_used + 1, closes_used))
            #左括号数量 ≥ 右括号数量
            if closes_used < opens_used:
                queue.append((current + ')', opens_used, closes_used + 1))
    
    return result


#测试
print(gen_parentheses(3))
