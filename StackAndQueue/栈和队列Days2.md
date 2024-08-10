# 栈和队列Days2

## [150. 逆波兰表达式求值](https://leetcode.cn/problems/evaluate-reverse-polish-notation/)

```c++
class Solution {
public:
    int evalRPN(vector<string>& s) {
        stack<int> st;
        for (int i = 0; i < s.size(); i++) {
            if (s[i] == "+" || s[i] == "-" || s[i] == "*" || s[i] == "/") {
                int num2 = st.top();
                st.pop();
                int num1 = st.top();
                st.pop();
                if (s[i] == "+") {
                    st.push(num1 + num2);
                }
                else if (s[i] == "-") {
                    st.push(num1 - num2);
                }
                else if (s[i] == "*") {
                    st.push(num1 * num2);
                }
                else if (s[i] == "/") {
                    st.push(num1 / num2);
                }
            }
            else {
                st.push(stoi(s[i]));
            }
        }
        int value = st.top();
        st.pop();
        return value;
    }
};
```

## [239. 滑动窗口最大值](https://leetcode.cn/problems/sliding-window-maximum/)

```c++
class Solution {
public:
    class MyQueue {
    public:
        deque<int> deq;
        MyQueue() {
        }
        ~MyQueue() {
        }
        void push(int value) {
            while (!deq.empty() && value > deq.back()) {
                deq.pop_back();
            }
            deq.push_back(value);
        }
        void pop(int value) {
            if (!deq.empty() && value == deq.front()) {
                deq.pop_front();
            }
        }
        int front() {
            return deq.front();
        }
    };
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        MyQueue myqueue;
        for (int i = 0; i < k; i++) {
            myqueue.push(nums[i]);
        }
        res.push_back(myqueue.front());
        for (int i = k; i < nums.size(); i++) {
            myqueue.pop(nums[i - k]);
            myqueue.push(nums[i]);
            res.push_back(myqueue.front());
        }
        return res;
    }
};
```

## [347. 前 K 个高频元素](https://leetcode.cn/problems/top-k-frequent-elements/)

```c++
class Solution {
public:
    class Comparsion {
    public:
        bool operator()(const pair<int, int> &lhs, const pair<int, int> &rhs) {
            return lhs.second > rhs.second;
        }
    };
  
public:
    vector<int> topKFrequent(vector<int>& nums, int k) {
        // key:   元素
        // value: 元素出现的频率
        unordered_map<int, int> umap;
        for (int i = 0; i < nums.size(); i++) {
            umap[nums[i]]++;
        }
        priority_queue<pair<int, int>, vector<pair<int, int>>, Comparsion> priQue;
        for (auto iter = umap.begin(); iter != umap.end(); iter++) {
            priQue.push(*iter);
            if (priQue.size() > k) {
                priQue.pop();
            }
        }
        vector<int> res(k);
        for (int i = k - 1; i >= 0; i--) {
            res[i] = priQue.top().first;
            priQue.pop();
        }
        return res;
    }
};
```

