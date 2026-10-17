// 练习                                                     扁平化嵌套列表迭代器
//                                      给你一个嵌套的整数列表 nestedList 。每个元素要么是一个整数，要么是一个列表；该列表的元素也可能是整数或者是其他列表。请你实现一个迭代器将其扁平化，使之能够遍历这个列表中的所有整数。
//                                      实现扁平迭代器类 NestedIterator ：
//                                      NestedIterator(List<NestedInteger> nestedList) 用嵌套列表 nestedList 初始化迭代器。
//                                      int next() 返回嵌套列表的下一个整数。
//                                      boolean hasNext() 如果仍然存在待迭代的整数，返回 true ；否则，返回 false 。
//                                      你的代码将会用下述伪代码检测：
//                                      initialize iterator with nestedList
//                                      res = []
//                                      while iterator.hasNext()
//                                          append iterator.next() to the end of res
//                                      return res
//                                      如果 res 与预期的扁平化列表匹配，那么你的代码将会被判为正确。




#include <bits/stdc++.h>
using namespace std;

class NestedInteger {
public:
    // Return true if this NestedInteger holds a single integer, rather than a nested list.
    bool isInteger() const;

    // Return the single integer that this NestedInteger holds, if it holds a single integer
    // The result is undefined if this NestedInteger holds a nested list
    int getInteger() const;

    // Return the nested list that this NestedInteger holds, if it holds a nested list
    // The result is undefined if this NestedInteger holds a single integer
    const vector<NestedInteger> &getList() const;
};

class NestedIterator {
private:
    stack<NestedInteger> st;

public:
    NestedIterator(vector<NestedInteger> &nestedList){
        // 逆序入栈
        for (int i = nestedList.size() - 1; i >= 0; i--) {
            st.push(nestedList[i]);
        }
    }

    int next() {
        // hasNext已经保证栈顶一定是整数
        NestedInteger cur = st.top();
        st.pop();
        return cur.getInteger();
    }

    bool hasNext() {
        // 循环展开：只要栈不为空，并且栈顶是列表，就拆开
        while(!st.empty()) {
            NestedInteger cur = st.top();
            if (cur.isInteger()) {
                return true;
            }
            // 栈顶是列表，弹出，逆序把内部元素压栈
            st.pop();
            auto& subList = cur.getList();
            for(int i = subList.size()-1; i >= 0; i--) {
                st.push(subList[i]);
            }
        }
        return false;
    }
};