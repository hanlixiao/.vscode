#练习        员工薪资跟踪


#创建员工类
class Employee:
    _base_salaries = {'trainee': 1000, 'junior': 2000, 'mid-level': 3000, 'senior': 4000}

    def __init__(self, name, level):
        if not isinstance(name, str) or not isinstance(level, str):
            raise TypeError("'name' and 'level' attribute must be of type 'str'.")
        self._name = name
        self._level = level
        
    def __str__(self):
        return f'{self.name}: {self.level}'
    
    @property
    def name(self):
        return self._name
    
    @property
    def level(self):
        return self._level
    
    def __repr__(self):
        return f"Employee('{self.name}', '{self.level}')"



#测试
charlie_brown = Employee('Charlie Brown', 'trainee')
print(charlie_brown)
