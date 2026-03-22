#练习        构建哈希表


#创建哈希表类
class HashTable:
    #构造函数创建字典属性
    def __init__(self):
        self.collection = {}

    #计算key的哈希值
    def hash(self, key):
        hash_value = 0
        #遍历每一个字符来计算Unicode值之和
        for char in key:
            hash_value += ord(char)
        return hash_value

    #添加值点对
    def add(self, key, value):
        h = self.hash(key)
        #如果哈希值不存在 则创建新的字典并嵌套
        if h not in self.collection:
            self.collection[h] = {}
        self.collection[h][key] = value

    #删除对应的key
    def remove(self, key):
        h = self.hash(key)
        #先判断key是否在字典中 不存在直接返回
        if h not in self.collection:
            return
        #如果存在则删除
        nested_dict = self.collection[h]
        if key in nested_dict:
            del self.collection[h][key]

    #查询key对应的值
    def lookup(self, key):
        h = self.hash(key)
        #如果不存在则返回为空
        if h not in self.collection:
            return None
        #存在则返回对应的值
        nested_dict = self.collection[h]
        return nested_dict.get(key, None)