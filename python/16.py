#练习        玩家移动


#引入抽象 和随机库
import abc
import random

#创建玩家类
class Player(abc.ABC):
    #构造函数玩家的移动 位置和路径
    def __init__(self):
        self.moves = []
        self.position = (0, 0)
        self.path = [self.position]

    #移动函数
    def make_move(self):
        #随机从移动方式中选取一个尽享移动
        selected_move = random.choice(self.moves)
        move_x, move_y = selected_move
        current_x, current_y = self.position
        new_x = current_x + move_x
        new_y = current_y + move_y
        #将当前位置改为新位置
        self.position = (new_x, new_y)
        #添加移动路径
        self.path.append(self.position)
        
        return self.position
    
    #抽象升级移动函数  子类实现
    @abc.abstractmethod
    def level_up(self):
        pass

#创建子类
class Pawn(Player):
    #继承父类构造函数 并添加moves值
    def __init__(self):
        super().__init__()
        self.moves = [(0, 1), (0, -1), (1, 0), (-1, 0)]

    #覆写level——up函数
    def level_up(self):
        diagnonal_moves = [(-1, 1), (1, 1), (-1, -1), (1, -1)]
        self.moves.extend(diagnonal_moves)
