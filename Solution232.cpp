
//题目232，Implement Queue using Stacks 用栈来实现队列
//题目225，Implement Stack using Queues

//借助辅助栈实现翻转
class Queue {
public:
    void push(int x) {
        stack<int> tmp;
        while (!oldStack.empty()) {
            tmp.push(oldStack.top());
            oldStack.pop();
        }
        oldStack.push(x);
        while (!tmp.empty()) {
            oldStack.push(tmp.top());
            tmp.pop();
        }
    }
    void pop(void) {
        oldStack.pop();
    }
    int peek(void) {
        return oldStack.top();
    }
    bool empty(void) {
        return oldStack.empty();
    }
private:
    stack<int> oldStack;
};

class Queue {
public:
    void push(int x) {
        _new.push(x);
    }
    void shiftStack() {
        if (_old.empty()) {
            while (!_new.empty()) {
                _old.push(_new.top());
                _new.pop();
            }
        }
    }
    void pop(void) {
        shiftStack();
        if (!_old.empty())
            _old.pop();
    }
    int peek(void) {
        shiftStack();
        if (!_old.empty())
            return _old.top();
        return 0;
    }
    bool empty(void) {
        return _old.empty() && _new.empty();
    }
private:
    stack<int> _old, _new;
};
