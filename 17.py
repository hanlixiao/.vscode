#练习        矩形正方形



#导入math库
import math

#创建矩形类
class Rectangle:
    #初始化宽和高
    def __init__(self, width, height):
        self.width = width
        self.height = height

    #设置宽函数
    def set_width(self, width):
        self.width = width

    #设置高函数
    def set_height(self, height):
        self.height = height

    #获取面积函数
    def get_area(self):
        return self.height * self.width
    
    #获取周长函数
    def get_perimeter(self):
        return 2 * (self.width + self.height)

    #巨酸对角线长度函数
    def get_diagonal(self):
        return math.sqrt(self.height * self.height + self.width * self.width)
    
    #打印图形函数
    def get_picture(self):
        #判断图形是否过大
        if self.width > 50 or self.height > 50:
            return "Too big for picture."
        
        picture = ""
        for _ in range(self.height):
            picture += "*" * self.width + "\n"
        return picture
    
    #计算图形中能放下几个其他图形
    def get_amount_inside(self, shap):
        width_fit = self.width // shap.width
        height_fit = self.height // shap.height
        return width_fit * height_fit
    
    #打印函数
    def __str__(self):
        return f"Rectangle(width={self.width}, height={self.height})"
    
#创建子类 正方形类
class Square(Rectangle):
    #继承父类并设置宽
    def __init__(self, side):
        super().__init__(side, side)

    #设置宽
    def set_width(self, width):
        self.set_side(width)
    
    #设置高
    def set_height(self, height):
        self.set_side(height)
    
    #设置边长
    def set_side(self, side):
        self.height = side
        self.width = side

    #输出函数
    def __str__(self):
        return f"Square(side={self.width})"