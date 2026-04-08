#练习           职工工资管理


#创建员工类
class Employee:
    #不同职位对应不同工资
    _base_salaries = {
        'trainee': 1000,
        'junior': 2000,
        'mid-level': 3000,
        'senior': 4000,
    }

    #构造函数传入姓名和职位
    def __init__(self, name, level):
        #判断是否为str
        if not (isinstance(name, str) and isinstance(level, str)):
            raise TypeError("'name' and 'level' attribute must be of type 'str'.")
        #判断是否为正确职位
        if level not in Employee._base_salaries:
            raise ValueError(f"Invalid value '{level}' for 'level' attribute.")
        self._name = name
        self._level = level
        self._salary = Employee._base_salaries[level]

    #输出
    def __str__(self):
        return f'{self.name}: {self.level}'

    #输出查看
    def __repr__(self):
        return f"Employee('{self.name}', '{self.level}')"

    #让name可以查看
    @property
    def name(self):
        return self._name

    #name可以修改
    @name.setter
    def name(self, new_name):
        #判断新name是否合规
        if not isinstance(new_name, str):
            raise TypeError("'name' must be a string.")
        self._name = new_name
        print(f"'name' updated to '{self.name}'.")

    #查看level
    @property
    def level(self):
        return self._level

    #level修改
    @level.setter
    def level(self, new_level):
        #判断level是否合规
        if new_level not in Employee._base_salaries:
            raise ValueError(f"Invalid value '{new_level}' for 'level' attribute.")
        #判断新level与旧level是否相等
        if new_level == self.level:
            raise ValueError(f"'{self.level}' is already the selected level.")
        #判断新level的薪水是否大于旧level的薪水
        if Employee._base_salaries[new_level] < Employee._base_salaries[self.level]:
            raise ValueError(f"Cannot change to lower level.")
        print(f"'{self.name}' promoted to '{new_level}'.")
        self.salary = Employee._base_salaries[new_level]
        self._level = new_level

    #查看薪水
    @property
    def salary(self):
        return self._salary

    #修改薪水
    @salary.setter
    def salary(self, new_salary):
        #判断薪水是否合规
        if not isinstance(new_salary, (int, float)):
            raise TypeError("'salary' must be a number.")
        #判断新薪水是否大于旧薪水
        if new_salary <= Employee._base_salaries[self.level]:
            raise ValueError(f'Salary must be higher than minimum salary ${Employee._base_salaries[self.level]}.')
        self._salary = new_salary
        print(f'Salary updated to ${self.salary}.')


#测试
charlie_brown = Employee('Charlie Brown', 'trainee')
print(charlie_brown)
print(f'Base salary: ${charlie_brown.salary}')
charlie_brown.level = 'junior'