
//题目225，Implement Stack using Queues 用队列来实现栈
//题目232，Implement Queue using Stacks

class Solution {
public:
    void push(int x) {
        queue<int> tmp;
        while (!oldQueue.empty()) {
            tmp.push(oldQueue.front());
            oldQueue.pop();
        }
        oldQueue.push(x);
        while (!tmp.empty()) {
            oldQueue.push(tmp.front());
            tmp.pop();
        }
    }
    void pop() {
        oldQueue.pop();
    }
    int top() {
        return oldQueue.front();
    }
    bool empty() {
        return oldQueue.empty();
    }
private:
    queue<int> oldQueue;
};

class Solution {
public:
    void push(int x) {
        q2.push(x);
        while (q2.size() > 1) {
            q1.push(q2.front());
            q2.pop();
        }
    }
    void pop() {
        top();
        q2.pop();
    }
    int top() {
        if (q2.empty()) {
            for (int i=0; i<(int)q1.size()-1; ++i) {
                q1.push(q1.front());
                q1.pop();
            }
            q2.push(q1.front());
            q1.pop();
        }
        return q2.front();
    }
    bool empty() {
        return q1.empty() && q2.empty();
    }
private:
    queue<int> q1, q2;
};
