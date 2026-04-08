#练习        乐器类


#定义乐器类
class MusicalInstrument:
    #构造函数
    def __init__(self, name, instrument_type):
        self.name = name
        self.instrument_type = instrument_type

    #演奏乐器函数
    def play(self):
        print(f'The {self.name} is fun to play!')

    #返回乐器种类函数
    def get_fact(self):
        return f'The {self.name} is part of the {self.instrument_type} family of instruments.'

#创建类
instrument_1 = MusicalInstrument('Oboe', 'woodwind')
instrument_2 = MusicalInstrument('Trumpet', 'brass')

#调用类中的函数
instrument_1.play()
print(instrument_1.get_fact())

instrument_2.play()
print(instrument_2.get_fact())