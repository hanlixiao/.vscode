#练习          构建用户配置管理器


#测试字典
test_settings = {'theme': 'dark', 'notifications': 'enabled', 'volume': 'high'}

#添加设置函数
def add_setting(dictionary, tupel):
    #将传入的元组key和value都改为小写
    key = tupel[0].lower()
    value = tupel[1].lower()
    #判断设置是否存在
    if key in dictionary:
        return f"Setting '{key}' already exists! Cannot add a new setting with this name."
    #不存在时添加
    dictionary[key] = value
    return f"etting '{key}' added with value '[value]' successfully!"

#更新设置函数
def update_setting(dictionary, tupel):
    #将传入的元组key和value都改为小写
    key = tupel[0].lower()
    value = tupel[1].lower()
    #判断设置是否存在
    if not key in dictionary:
        return f"Setting '{key}' does not exist! Cannot update a non-existing setting."
    #存在时更新
    dictionary[key] = value
    return f"Setting '{key}' updated to '{value}' successfully!"

#删除设置函数
def delete_setting(dictionary, key):
    #将key改为小写
    key = key.lower()
    #判断key是否存在
    if not key in dictionary:
        return f"Setting not found!"
    #存在时删除
    del dictionary[key]
    return f"Setting '{key}' deleted successfully!"

#查看设置函数
def view_settings(dictionary):
    #判断设置字典是否为空
    if dictionary == {}:
        return 'No settings available.'
    #创建返回变量
    result = "Current User Settings:\n"
    #动态添加到返回变量
    for key, value in dictionary.item():
        formatted_key = key.capitalize()
        result += f"{formatted_key}: {value}\n"
    return result