#练习        预算清单



#清单类
class Category:
    #构造函数 名称和对应商品列表
    def __init__(self, name):
        self.name = name
        self.ledger = []
    
    #最初的资金（存入的钱）
    def deposit(self, amount, description):
        self.ledger.append({'amount': amount, 'description': description})

    #计算还剩多少钱
    def get_balance(self):
        return sum(item['amount'] for item in self.ledger)

    #检查钱还够不够
    def check_funds(self, amount):
        return amount <= self.get_balance()

    #花费金额添加
    def withdraw(self, amount, description):
        if self.check_funds(amount):
            self.ledger.append({'amount': -amount, 'description': description})
            return True
        return False
    
    #转账
    def transfer(self, amount, name):
        if self.check_funds(amount):
            self.withdraw(amount, f'Transfer to {name}')
            name.deposit(self.amount, f'Transfer from {self.name}')
            return True
        return False
    
    #打印函数
    def __str__(self):
        title = self.name.center(30, "*") + "\n"
        for item in self.ledger:
            desc = item['description'][:23].ljust(23)
            amt = f'{item['amount']:.2f}'.rjust(7)
            line += f'{desc}{amt}\n'
        
        total = f'Total: {self.get_balance():.2f}'
        
        return title + line + total

#打印表格函数
def create_spend_chart(categories):
    #创建每一类商品所花的钱的列表
    spend_per = []
    #计算每一类所花的总价钱
    for cat in categories:
        total_spend = sum(-item['amount'] for item in cat.ledger if item['amount'] < 0)
        spend_per.append(total_spend)
    #计算所有种类的总价钱
    total_spend_all = sum(spend_per)
    #如果总共花了0元
    if total_spend_all == 0:
        #创建都为零的列表  元素有categories长度个
        percentages = [0] * len(categories)
    #否则计算每个种类的长度存入列表
    else:
        percentages = [int((spend / total_spend_all) * 100)//10 * 10 for spend in spend_per]

    #表格头
    chart = 'Percentage spent by category\n'
    #循环遍历半分比并添加物品所占半分比
    for y in range(100, -1, 10):
        line = f'{y:3d}|'
        for pct in percentages:
            line += 'o' if pct >= y else ' '
        #在最后加上两个空格
        line += '  '
    #整合表格
    chart += line + '\n'

    #构建水平线
    horizontal_line = '   ' + '-' * (3 * len(categories) + 2) + '\n'
    chart += horizontal_line

    #显示种类名称
    #找到最长种类名
    max_name_len = max(len(cat.name) for cat in categories)
    #逐行生成
    for i in range(max_name_len):
        line = '    '
        #每个类别按字母逐个打印 无字母则为空格
        for cat in categories:
            char = cat.name[i] if i < len(cat.name) else ' '
            line += '  '
            #最后一行无换行符
            if i == max_name_len:
                #移除换行符
                chart += line.rstrip()
            else:
                chart += line + '\n'

    #返回表格
    return chart