#练习        构建Planet类


#创建Planet类
class Planet:
    #类的构造函数
    def __init__(self, name, planet_type, star):
        #将参数传入列表
        params = [name, planet_type,star]
        #遍历检查参数只能为str类型，并且不为空
        for param in params:
            if not isinstance(param, str):
                raise TypeError('name, planet type, and star must be strings')
        
        for param in params:
            if param == '':
                raise ValueError("name, planet_type, and star must be non-empty strings")
        
        #将参数存储
        self.name =name
        self.planet_type = planet_type
        self.star = star

    #构建orbit函数
    def orbit(self):
        return f'{self.name} is orbiting around {self.star}...'
    
    #构建__str__
    def __str__(self):
        return f'Planet: {self.name} | Type: {self.planet_type} | Star: {self.star}'

#创建实例
planet_1 = Planet('1', '1', '1')
planet_2 = Planet('1', '1', '1')
planet_3 = Planet('1', '1', '1')

#打印测试
print(planet_1)
print(planet_2)
print(planet_3)

print(planet_1.orbit())
print(planet_2.orbit())
print(planet_3.orbit())