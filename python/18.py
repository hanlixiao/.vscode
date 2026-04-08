#练习         链表


#创建链表
class LinkedList:
    #创建小节点
    class Node:
        def __init__(self, element):
            self.element = element
            self.next = None
            
    #链表的构造函数 头链表
    def __init__(self):
        self.length = 0
        self.head = None

    #判断链表是否为空
    def is_empty(self):
        return self.length == 0

    #为链表添加元素
    def add(self, element):
        #先创建下一个小链表
        node = self.Node(element)
        #判断链表是否为空 为空则为头链表
        if self.is_empty():
            self.head = node
        #否则遍历整个链表 直到最后一个链表 并将原酸添加到后面
        else:
            current_node = self.head
            while current_node.next is not None:
                current_node = current_node.next
            current_node.next = node
        #添加元素后链表长度加1
        self.length += 1

    #删除元素
    def remove(self, element):
        previous_node = None
        current_node = self.head
        #遍历整个链表 直到找到要删除的元素 或者遍历结束未找到
        while current_node is not None and current_node.element != element:
            previous_node = current_node
            current_node = current_node.next
        #如果未找到直接返回
        if current_node is None:
            return
        #如果找到则直接跳过 删除元素   
        elif previous_node is not None:
            previous_node.next = current_node.next
        #如果删除的是头节点 则把下一个节点设置为头节点
        else:
            self.head = current_node.next
        #删除后列表长度减1
        self.length -= 1



#测试
my_list = LinkedList()
print(my_list.is_empty())

my_list.add(1)
my_list.add(2)
print(my_list.is_empty())
print(my_list.length)

