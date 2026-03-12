class Category:
    def __init__(self, name):
        self.name = name
        self.ledger = []
    
    def deposit(self, amount, description):
        self.ledger.append({'amount': amount, 'description': description})

    def get_balance(self):
        return sum(item['amount'] for item in self.ledger)

    def check_funds(self, amount):
        return amount <= self.get_balance()

    def withdraw(self, amount, description):
        if self.check_funds(amount):
            self.ledger.append({'amount': -amount, 'description': description})
            return True
        return False
    
    def transfer(self, amount, name):
        if self.check_funds(amount):
            self.withdraw(amount, f'Transfer to {name}')
            name.deposit(self.amount, f'Transfer from {self.name}')
            return True
        return False
    
    def __str__(self):
        print()

def create_spend_chart(categories):
    pass