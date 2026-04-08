#练习          商品的打折策略


#导入抽象
from abc import ABC, abstractmethod

#创建商品类
class Product:
    #构造函数  包含名称 价格 可以使用冒号来提示传入的数据类型  使用->来提示返回类型
    def __init__(self, name: str, price: float) -> None:
        self.name = name
        self.price = price

    #输出函数
    def __str__(self) -> str:
        return f'{self.name} - ${self.price}'

#创建抽象类 并定义两个抽象函数
class DiscountStrategy(ABC):
    @abstractmethod
    def is_applicable(self, product: Product, user_tier: str) -> bool:
        pass

    @abstractmethod
    def apply_discount(self, product: Product) -> float:
        pass

#创建第一种打折方法
class PercentageDiscount(DiscountStrategy):
    def __init__(self, percent: int) -> None:
        self.percent = percent

    def is_applicable(self, product: Product, user_tier: str) -> bool:
        return self.percent <= 70

    def apply_discount(self, product: Product) -> float:
        return product.price * (1 - self.percent / 100)

#创建第二种打折方法
class FixedAmountDiscount(DiscountStrategy):
    def __init__(self, amount: int) -> None:
        self.amount = amount

    def is_applicable(self, product: Product, user_tier: str) -> bool:
        return product.price * 0.9 > self.amount

    def apply_discount(self, product: Product) -> float:
        return product.price - self.amount

#创建第三种打折方法
class PremiumUserDiscount(DiscountStrategy):
    def is_applicable(self, product: Product, user_tier: str) -> bool:
        return user_tier.lower() == 'premium'

    def apply_discount(self, product: Product) -> float:
        return product.price * 0.8

#创建打折策略管理类
class DiscountEngine:
    #构造函数 传入包含DiscountStrategy类的列表
    def __init__(self, strategies: list[DiscountStrategy]) -> None:
        self.strategies = strategies

    #计算最便宜的打折方法
    def calculate_best_price(self, product: Product, user_tier: str) -> float:
        prices = [product.price]

        for strategy in self.strategies:
            if strategy.is_applicable(product, user_tier):
                discounted = strategy.apply_discount(product)
                prices.append(discounted)

        return min(prices)


#测试
if __name__ == '__main__':
    product = Product('Wireless Mouse', 50.0)
    user_tier = 'Premium'

    strategies = [
        PercentageDiscount(10),
        FixedAmountDiscount(5),
        PremiumUserDiscount()
    ]

    engine = DiscountEngine(strategies)
    best_price = engine.calculate_best_price(product, user_tier)