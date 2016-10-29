
//题目224，Basic Calculator 基本计算器
//题目227，Basic Calculator II

class Solution {
public://没有管优先级，从左到右依次计算，只用符号数组存储了一下符号
    int calculate(string s) {
        int res = 0;
        vector<int> sign(2,1);//符号数组
        for (int i=0; i<s.size(); ++i) {
            char c = s[i];
            if (c >= '0') {
                int num = 0;
                while (i<s.size() && s[i]>='0')//取出组拼数字
                    num = 10*num + sum[i++] - '0';
                res += sign.back() * num;
                sign.pop_back();
                --i;
            }
            else if (c == ')') sign.pop_back();//遇到右括号，弹出最后一个符号
            else if (c != ' ') sign.push_back(sign.back()*(c == '-' ? -1 : 1));
        }
        return res;
    }
};

public class Solution {
    public int calculate(String s) {
        int len = s.length(), sign = 1, res = 0; //sign保存运算符号
        Stack<Integer> stack = new Stack<Integer>();//借助栈实现运算
        for (int i=0; i<len; i++) {
            if (Character.isDigit(s.charAt(i))) {
                int sum = s.charAt(i) - '0';
                while (i+1<len && Character.isDigit(s.charAt(i+1))) {
                    sum = sum*10 + s.charAt(i+1) - '0';
                    i++;
                }
                res += sum*sign;
            } else if (s.charAt(i) == '+')
                sign = 1;
            else if (s.charAt(i) == '-')
                sign = -1;
            else if (s.charAt(i) == '(') {
                stack.push(res);
                stack.push(sign);
                res = 0;
                sign = 1;
            } else if (s.charAt(i) == ')') {
                res = res*stack.pop() + stack.pop();
            }
        }
        return res;
    }
}
