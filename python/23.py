#练习              快速排序


#排序函数
def quick_sort(arr):
    # 递归终止条件：空 或 1个元素，直接返回
    if len(arr) <= 1:
        return arr.copy()  # 确保不修改原数组，返回新列表

    # 选择第一个元素作为枢轴
    pivot = arr[0]

    # 分成三个部分：小于、等于、大于
    less = []
    equal = []
    greater = []

    for num in arr:
        if num < pivot:
            less.append(num)
        elif num == pivot:
            equal.append(num)
        else:
            greater.append(num)

    # 递归 + 拼接
    return quick_sort(less) + equal + quick_sort(greater)