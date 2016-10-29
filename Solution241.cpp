
//题目241，Different Ways to Add Parentheses 添加括号的不同方式

public class Solution {
    public List<Integer> diffWaysToCompute(String input) {
        List<Integer> ret = new LinkedList<Integer>();
        for (int i=0; i<input.length(); i++) {
            //检测是否是运算符
            if (inpput.charAt(i)=='+' || input.charAt(i)=='-' || input.charAt(i)=='*') {
                String part1 = input.substring(0,i);//子串1
                String part2 = input.substring(i+1);//子串2
                List<Integer> part1Ret = diffWaysToCompute(part1);//将子串1递归调用函数本身
                List<Integer> part2Ret = diffWaysToCompute(part2);//将子串2递归调用函数本身

                for (Integer p1 : part1Ret) {//轮训两个子串的返回值，计算结果
                    for (Integer p2 : part2Ret) {
                        int c = 0;
                        switch (input.charAt(i)) {
                            case '+':
                                c = p1 + p2;
                                break;
                            case '-':
                                c = p1 - p2;
                                break;
                            case '*':
                                c = p1 * p2;
                                break;
                        }
                        ret.add(c);//将每种组合的计算结果值添加到List中
                    }
                }
            }
        }
        if (ret.size() == 0) {//如果没有往List中添加值，说明没有运算符，则直接将字符串转换为整数添加进去。
            ret.add(Integer.valueOf(input));
        }
        return ret;
    }
}

//C++版
class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        vector<int> res;
        for (int i=0; i<input.size(); ++i) {
            if (input[i]=='+' || input[i]=='-' || input[i]=='*') {
                vector<int> left = diffWaysToCompute(input.substr(0,i));
                vector<int> right = diffWaysToCompute(input.substr(i+1));
                for (int j=0; j<left.size(); ++j) {
                    for (int k=0; k<right.size(); ++k) {
                        if (input[i] == '+') res.push_back(left[j] + right[k]);
                        else if (input[i] == '-') res.push_back(left[j] - right[k]);
                        else res.push_back(left[j] * right[k]);
                    }
                }
            }
        }
        if (res.empty()) res.push_back(atoi(input.c_str()));
        return res;
    }
};

class Solution {
public:
    vector<int> diffWaysToCompute(string input) {
        unordered_map<string, vector<int>> dpMap;
        return computeWithDP(input, dpMap);
    }
    vector<int> computeWithDP(string input, unordered_map<string, vector<int>> &dpMap) {
        vector<int> res;
        int size = input.size();
        for (int i=0; i<size; i++) {
            char cur = input[i];
            if (cur=='+' || cur=='-' || cur=='*') {
                vector<int> res1, res2;
                string substr = input.substr(0, i);
                if (dpMap.find(substr) != dpMap.end())
                    res1 = dpMap[substr];
                else
                    res1 = computeWithDP(substr, dpMap);

                substr = input.substr(i+1);
                if (dpMap.find(substr) != dpMap.end())
                    res2 = dpMap[substr];
                else
                    res2 = computeWithDP(substr, dpMap);

                for (auto n1 : res1) {
                    for (auto n2 : res2) {
                        if (cur == '+')
                            res.push_back(n1 + n2);
                        else if (cur == '-')
                            res.push_back(n1 - n2);
                        else
                            res.push_back(n1 * n2);
                    }
                }
            }
        }
        if (res.empty())
            res.push_back(atoi(input.c_str()));
        dpMap[input] = res;
        return res;
    }
};

