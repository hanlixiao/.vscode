
import math

class Rectangle:
    def __init__(self, width, height):
        self.width = width
        self.height = height

    def set_width(self, width):
        self.width = width

    def set_height(self, height):
        self.height = height

    def get_area(self):
        return self.height * self.width
    
    def get_perimeter(self):
        return 2 * (self.width + self.height)
    
    def get_diagonal(self):
        return math.sqrt(self.height * self.height + self.width * self.width)
    
    def get_picture(self):
        if self.width > 50 or self.height > 50:
            return "Too big for picture."
        picture = ""
        for _ in range(self.height):
            picture += "*" * self.width + "\n"
        return picture
    
    def get_amount_inside(self, shap):
        width_fit = self.width // shap.width
        height_fit = self.height // shap.height
        return width_fit * height_fit
    
    def __str__(self):
        return f"Rectangle(width={self.width}, height={self.height})"
    
class Square(Rectangle):
    def __init__(self, side):
        super().__init__(side, side)

    def set_width(self, width):
        self.set_side(width)
    
    def set_height(self, height):
        self.set_side(height)
    
    def set_side(self, side):
        self.height = side
        self.width = side

    def __str__(self):
        return f"Square(side={self.width})"