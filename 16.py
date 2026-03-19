#练习



import abc
import random

class Player(abc.ABC):
    def __init__(self):
        self.moves = []
        self.position = (0, 0)
        self.path = [self.position]

    def make_move(self):
        selected_move = random.choice(self.moves)
        move_x, move_y = selected_move
        current_x, current_y = self.position
        new_x = current_x + move_x
        new_y = current_y + move_y
        self.position = (new_x, new_y)
        self.path.append(self.position)
        
        return self.position
    
    @abc.abstractmethod
    def level_up(self):
        pass

class Pawn(Player):
    def __init__(self):
        super().__init__()
        self.moves = [(0, 1), (0, -1), (1, 0), (-1, 0)]

    def level_up(self):
        diagnonal_moves = [(-1, 1), (1, 1), (-1, -1), (1, -1)]
        self.moves.extend(diagnonal_moves)
