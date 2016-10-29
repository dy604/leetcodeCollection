
//题目155，Min Stack 最小栈

class MinStack {
public:
    MinStack() {

    }

    void push(int x) {
        _stack.push(x);
        if (_minStack.empty() || x<=_minStack.top())
            _minStack.push(x);
    }
    void pop() {
        if (!_stack.empty()) {
            if (_stack.top()==_minStack.top()) _minStack.pop();
            _stack.pop();
        }
    }
    int top() {
        if (!_stack.empty()) return _stack.top();
        return 0;
    }
    int getMin() {
        if (!_minStack.empty()) return _minStack.top();
        return 0;
    }
private:
    stack<int> _stack;
    stack<int> _minStack;
};

public class Solution {
    long min;
    Stack<Long> stack;

    public MinStack() {
        stack = new Stack<Long>();
    }
    public void push(int x) {
        if (stack.isEmpty()) {
            stack.push(0L);
            min = x;
        } else {
            stack.push(x-min);
            if (x < min) min = x;
        }
    }
    public void pop() {
        if (stack.isEmpty()) return ;
        long pop = stack.pop();
        if (pop < 0) min = min - pop;
    }
    public int top() {
        long top = stack.peek();
        if (top > 0) {
            return (int)(top+min);
        } else {
            return (int)(min);
        }
    }
    public int getMin() {
        return (int)min;
    }
}

public class Solution {
    static class Element {
        final int value;
        final int min;
        Element (final int value, final int min) {
            this.value = value;
            this.min = min;
        }
    }

    final Stack<Element> stack = new Stack<Element>();
    public void push(int x) {
        final int min = (stack.empty()) ? x : Math.min(stack.peek().min, x);
        stack.push(new Element(x, min));
    }
    public void pop() {
        stack.pop();
    }
    public int top() {
        return stack.peek().value;
    }
    public int getMin() {
        return stack.peek().min;
    }
}
