
//题目227，Basic Calculator II 基本计算器之二
//题目224，Basic Calculator

public class Solution {
    public int calculate(String s) {
        int len;
        if (s == null || (len = s.length()) == 0) return 0;
        Stack<Integer> stack = new Stack<Integer>();
        int num = 0;
        char sign = '+';
        for (int i=0; i<len; i++) {
            if (Character.isDigit(s.charAt(i))) {  //处理表达式中的数字
                num = num*10 + s.charAt(i) - '0';
            }
            if ((!Character.isDigit(s.charAt(i)) && ' '!=s.charAt(i)) || i == len-1) { //处理操作符
                if (sign == '-') {
                    stack.push(-num);
                }
                if (sign == '+') {
                    stack.push(num);
                }
                if (sign == '*') {
                    stack.push(stack.pop()*num);
                }
                if (sign == '/') {
                    stack.push(stack.pop()/num);
                }
                sign = s.charAt(i);  //保存当前运算符
                num = 0;
            }
        }

        int res = 0;
        for (int i : stack) { //将堆栈中的所有数累加
            res += i;
        }
        return res;
    }
}

class Solution {
public:
    int calculate(string s) {
        int result = 0, cur_res = 0;
        char op = '+';
        for (int pos=s.find_first_not_of(' '); pos<s.size(); pos=s.find_first_not_of(' ', pos)) {
            if (isdigit(s[pos])) {
                int tmp = s[pos] - '0';
                while (++pos < s.size() && isdigit(s[pos]))  //得到表达式中的一个完整操作数
                    tmp = tmp*10 + (s[pos] - '0');
                switch(op) { //根据操作符做相应的运算
                    case '+':
                        cur_res += tmp;
                        break;
                    case '-':
                        cur_res -= tmp;
                        break;
                    case '*':
                        cur_res *= tmp;
                        break;
                    case '/':
                        cur_res /= tmp;
                        break;

                }
            } else {
                if (s[pos] == '+' || s[pos] == '-') {
                    result += cur_res;
                    cur_res = 0;
                }
                op = s[pos++];
            }
        }
        return result + cur_res;
    }
};
