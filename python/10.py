#练习            邮件系统


#导入datetime库 用于显示时间戳
import datetime

#创建Email类
class Email:
    #Email类的构造函数包含sender, receiver, subject, body, timestamp等元素
    def __init__(self, sender, receiver, subject, body):
        self.sender = sender
        self.receiver = receiver
        self.subject = subject
        self.body = body
        self.timestamp = datetime.datetime.now()
        self.read = False

    #定义mark_as_read函数标记是否读过
    def mark_as_read(self):
        self.read = True

    #展示Email函数
    def display_full_email(self):
        self.mark_as_read()
        print('\n--- Email ---')
        print(f'From: {self.sender.name}')
        print(f'To: {self.receiver.name}')
        print(f'Subject: {self.subject}')
        print(f"Received: {self.timestamp.strftime('%Y-%m-%d %H:%M')}")
        print(f'Body: {self.body}')
        print('------------\n')

    #打印函数
    def __str__(self):
        status = 'Read' if self.read else 'Unread'
        return f"[{status}] From: {self.sender.name} | Subject: {self.subject} | Time: {self.timestamp.strftime('%Y-%m-%d %H:%M')}"

#定义邮箱类
class Inbox:
    #构造函数 创建邮箱列表
    def __init__(self):
        self.emails = []

    #将邮件添加到邮箱
    def receive_email(self, email):
        self.emails.append(email)

    #展示邮件函数
    def list_emails(self):
        #如果邮箱为空
        if not self.emails:
            print('Your inbox is empty.\n')
            return
        #否则遍历打印
        print('\nYour Emails:')
        for i, email in enumerate(self.emails, start=1):
            print(f'{i}. {email}')

    #阅读邮件函数
    def read_email(self, index):
        #先检查邮箱是否为空
        if not self.emails:
            print('Inbox is empty.\n')
            return
        #定义真实索引
        actual_index = index - 1
        #检查索引是否合法
        if actual_index < 0 or actual_index >= len(self.emails):
            print('Invalid email number.\n')
            return
        #阅读邮件
        self.emails[actual_index].display_full_email()

    #删除邮件函数
    def delete_email(self, index):
        #检查邮箱是否为空
        if not self.emails:
            print('Inbox is empty.\n')
            return
        #定义真实索引
        actual_index = index - 1
        #检查索引是否合法
        if actual_index < 0 or actual_index >= len(self.emails):
            print('Invalid email number.\n')
            return
        #删除邮件
        del self.emails[actual_index]
        print('Email deleted.\n')
        
#定义用户类
class User:
    #构造函数 包含用户名等
    def __init__(self, name):
        self.name = name
        self.inbox = Inbox()

    #用户发送邮件功能函数
    def send_email(self, receiver, subject, body):
        email = Email(sender=self, receiver=receiver, subject=subject, body=body)
        receiver.inbox.receive_email(email)
        print(f'Email sent from {self.name} to {receiver.name}!\n')

    #查看邮箱功能函数
    def check_inbox(self):
        print(f"\n{self.name}'s Inbox:")
        self.inbox.list_emails()

    #阅读邮件函数
    def read_email(self, index):
        self.inbox.read_email(index)

    #删除邮件函数
    def delete_email(self, index):
        self.inbox.delete_email(index)

#测试函数
def main():
    tory = User('Tory')
    ramy = User('Ramy')        
    
    tory.send_email(ramy, 'Hello', 'Hi Ramy, just saying hello!')
    ramy.send_email(tory, 'Re: Hello', 'Hi Tory, hope you are fine.')
    
    ramy.check_inbox()
    ramy.read_email(1)
    ramy.delete_email(1)
    ramy.check_inbox()
    
if __name__ == '__main__':
    main()