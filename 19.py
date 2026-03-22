#



class HashTable:
    def __init__(self):
        self.collection = {}

    def hash(self, key):
        hash_value = 0
        for char in key:
            hash_value += ord(char)
        return hash_value

    def add(self, key, value):
        h = self.hash(key)
        if h not in self.collection:
            self.collection[h] = {}
        self.collection[h][key] = value

    def remove(self, key):
        h = self.hash(key)
        if h not in self.collection:
            return
        nested_dict = self.collection[h]
        if key in nested_dict:
            del self.collection[h][key]

    def lookup(self, key):
        h = self.hash(key)
        if h not in self.collection:
            return None
        nested_dict = self.collection[h]
        return nested_dict.get(key, None)