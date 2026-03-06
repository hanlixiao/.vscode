#练习         创建一个 RPG人物


#点数样例
full_dot = '●'
empty_dot = '○'

#创建人物函数
def create_character(name, STR, INT, CHA):
    
    #人物名必须为str类型
    if not isinstance(name, str):

        return 'The character name should be a string'
    
    #人物名不能为空
    elif name == '':

        return 'The character should have a name'
    
    #人物名不能太长
    elif len(name) > 10:

        return 'The character name is too long'
    
    #人物名中不能有空格
    if ' ' in name:

        return 'The character name should not contain spaces'
    
    #判断三个属性是否为int类型
    if not isinstance(STR, int) or not isinstance(INT, int) or not isinstance(CHA, int):

        return 'All stats should be integers'
    
    #判断属性点数是否大于1
    if STR < 1 or INT < 1 or CHA < 1:

        return 'All stats should be no less than 1'
    
    #判断人物点数是否小于4
    elif STR > 4 or INT > 4 or CHA >4:

        return 'All stats should be no more than 4'

    #判断是否符合分配点数和为7
    if STR + INT + CHA != 7:

        return 'The character should start with 7 points'
    
    #打印人物点数表函数
    def table(Name, val):

        return f"{Name} {full_dot * val}{empty_dot * (10 - val)}"
    
    #返回结果
    return f"{name}\n{table('STR', STR)}\n{table('INT',INT)}\n{table('CHA', CHA)}"