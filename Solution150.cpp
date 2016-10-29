
//题目150，Evaluate Reverse Polish Notation 计算逆波兰表达式

class Solution {
public:
    int evalRPN(vector<string> &tokens) {
        if (tokens.size()==1) return atoi(tokens[0].c_str());
        stack<int> stk;
        for (int i=0; i<tokens.size(); ++i) {
            if (tokens[i]!="+" && tokens[i]!="-" && tokens[i]!="*" && tokens[i]!="/") {
                stk.push(atoi(tokens[i].c_str()));
            } else {
                int operand1 = stk.top();
                stk.pop();
                int operand2 = stk.top();
                stk.pop();
                if (tokens[i] == "+") stk.push(operand1+operand2);
                if (tokens[i] == "-") stk.push(operand1-operand2);
                if (tokens[i] == "*") stk.push(operand1*operand2);
                if (tokens[i] == "/") stk.push(operand1/operand2);
            }
        }
        if (stk.size() == 1) {
            return stk.top();
        } else {
            return -1;
        }
    }
};

public class Solution {
    public int evalRPN(String[] tokens) {
        int a, b;
        Stack<Integer> stack = new Stack<Integer>();
        for (String s : tokens) {
            if (s.equals("+")) {
                a = stack.pop();
                b = stack.pop();
                stack.push(b + a);
            } else if (s.equals("-")) {
                a = stack.pop();
                b = stack.pop();
                stack.push(b - a);
            } else if (s.equals("*")) {
                a = stack.pop();
                b = stack.pop();
                stack.push(b * a);
            } else id (s.equals("/")) {
                a = stack.pop();
                b = stack.pop();
                stack.push(b / a);
            } else {
                stack.push(Integer.parseInt(s));
            }
        }
        return stack.pop();
    }
}
