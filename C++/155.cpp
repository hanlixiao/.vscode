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