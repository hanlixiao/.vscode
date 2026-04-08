#练习        选择排序


#选择排序函数
def selection_sort(arr):
    #循环遍历数组中每一个元素
    for i in range(len(arr)):
        #假设第i个元素为最小值
        min_index = i
        #对比i后每一个元素
        for j in range(i + 1, len(arr)):
            if arr[j] < arr[min_index]:
                min_index = j

        #如果最小值不在正确位置时才交换
        if min_index != i:
            arr[i], arr[min_index] = arr[min_index], arr[i]

    return arr