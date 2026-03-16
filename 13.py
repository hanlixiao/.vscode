#练习           游戏字符属性追踪器


#创建玩家类
class GameCharacter:
    #构造函数   包含玩家名 血量 蓝 等级
    def __init__(self, name):
        self._name = name
        self._health = 100
        self._mana = 50
        self._level = 1

    #name的读访问
    @property
    def name(self):
        return self._name
    
    #血量的读访问
    @property
    def health(self):
        return self._health
    
    #血量的写访问
    @health.setter
    def health(self, health):
        if health < 0:
            self._health = 0
        elif health > 100:
            self._health = 100
        else:
            self._health = health

    #蓝的访问
    @property
    def mana(self):
        return self._mana
    
    #蓝的写访问
    @mana.setter
    def mana(self, mana):
        if mana < 0:
            self._mana = 0
        elif mana > 50:
            self._mana = 50
        else:
            self._mana = mana

    #等级的读访问
    @property
    def level(self):
        return self._level
    
    #等级提升函数
    def level_up(self):
        self._level += 1
        self.health = 100
        self.mana = 50
        print(f"{self.name} leveled up to {self.level}!")

    #输出返回函数
    def __str__(self):
        return f"Name: {self.name}\nLevel: {self.level}\nHealth: {self.health}\nMana: {self.mana}"