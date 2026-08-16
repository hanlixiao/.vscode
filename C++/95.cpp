// 练习                                            最小栈
//                                设计一个支持 push ，pop ，top 操作，并能在常数时间内检索到最小元素的栈。
//                                实现 MinStack 类:
//                                MinStack() 初始化堆栈对象。
//                                void push(int value) 将元素 value 推入堆栈。
//                                void pop() 删除堆栈顶部的元素。
//                                int top() 获取堆栈顶部的元素。
//                                int getMin() 获取堆栈中的最小元素。




#include <bits/stdc++.h>
using namespace std;

class MinStack {
private:
    stack<int> st;
    stack<int> min_st;

public:
    MinStack() {
    }

    void push(int val) {
        st.push(val);
        if (min_st.empty()) {
            min_st.push(val);
        } else {
            if (val <= min_st.top()) {
                min_st.push(val);
            } else {
                min_st.push(min_st.top());
            }
        }
    }

    void pop() {
        st.pop();
        min_st.pop();
    }

    int top() {
        return st.top();
    }

    int getMin() {
        return min_st.top();
    }
};