# 栈和队列Days1

## [232. 用栈实现队列](https://leetcode.cn/problems/implement-queue-using-stacks/)

```c++
class MyQueue {
public:
    stack<int> stIn;
    stack<int> stOut;
public:
    MyQueue() {

    }
    
    void push(int x) {
        stIn.push(x);
    }
    
    int pop() {
        while (stOut.empty()) {
            while (!stIn.empty()) {
                stOut.push(stIn.top());
                stIn.pop();
            }
        }
        int topValue = stOut.top();
        stOut.pop();
        return topValue;
    }
    
    int peek() {
        int topValue = this->pop();
        stOut.push(topValue);
        return topValue;
    }
    
    bool empty() {
        return stIn.empty() && stOut.empty();
    }
};

/**
 * Your MyQueue object will be instantiated and called as such:
 * MyQueue* obj = new MyQueue();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->peek();
 * bool param_4 = obj->empty();
 */
```

## [225. 用队列实现栈](https://leetcode.cn/problems/implement-stack-using-queues/)

+ 两个队列：

```c++
class MyStack {
public:
    queue<int> queIn;
    queue<int> queOut;
public:
    MyStack() {

    }
    
    void push(int x) {
        queIn.push(x);
    }
    
    int pop() {
        while (queIn.size() > 1) {
            queOut.push(queIn.front());
            queIn.pop();
        }
        int vaule = queIn.back();
        queIn.pop();
        swap(queIn, queOut);
        return vaule;
    }
    
    int top() {
        int value = this->pop();
        this->push(value);
        return value;
    }
    
    bool empty() {
        return queIn.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
```

+ 一个队列：

```c++
class MyStack {
public:
    queue<int> que;
public:
    MyStack() {

    }
    
    void push(int x) {
        que.push(x);
    }
    
    int pop() {
        int size = que.size();
        while (size > 1) {
            que.push(que.front());
            que.pop();
            size--;
        }
        int value = que.front();
        que.pop();
        return value;
    }
    
    int top() {
        return que.back();
    }
    
    bool empty() {
        return que.empty();
    }
};

/**
 * Your MyStack object will be instantiated and called as such:
 * MyStack* obj = new MyStack();
 * obj->push(x);
 * int param_2 = obj->pop();
 * int param_3 = obj->top();
 * bool param_4 = obj->empty();
 */
```

## [20. 有效的括号](https://leetcode.cn/problems/valid-parentheses/)

```c++
class Solution {
public:
    bool isValid(string s) {
        stack<char> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == '{' || s[i] == '(' || s[i] == '[') {
                if (s[i] == '{') {
                    st.push('}');
                }
                else if (s[i] == '(') {
                    st.push(')');
                }
                else if (s[i] == '[') {
                    st.push(']');
                }
            }
            else if (!st.empty() && s[i] == st.top()) {
                st.pop();
            }
            else {
                return false;
            }
        }
        return st.empty();
    }
};
```

## [1047. 删除字符串中的所有相邻重复项](https://leetcode.cn/problems/remove-all-adjacent-duplicates-in-string/)

```c++
class Solution {
public:
    string removeDuplicates(string s) {
        string res;
        for (int i = 0; i < s.size(); i++) {
            if (res.empty() || res.back() != s[i]) {
                res.push_back(s[i]);
            }
            else {
                res.pop_back();
            }
        }
        return res;
    }
};
```

