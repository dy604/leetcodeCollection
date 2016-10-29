
//题目166，Fraction to Recurring Decimal 分数转循环小数

public class Solution {
    public String fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        if (denominator == 0) return "";
        String res = "";
        //判断结果是否为负数,加负号
        if ((numerator<0)^(denominator<0)) res += "-";
        //保证分子分母都为正数，防止取绝对值溢出，先将int转换为long，再取绝对值
        long num = numerator;
        long den = denominator;
        num = Math.abs(num);
        den = Math.abs(den);
        //得到结果的整数部分
        long numInt = num/den;
        res += String.valueOf(numInt);
        //判断是否能整除，如果能，则直接返回结果
        long numres = (num%den)*10;
        if (numres == 0) return res;
        //结果的小数部分
        HashMap<Long, Integer> map = new HashMap<Long, Integer>();
        res += ".";
        while (numres != 0) {
            //判断map中是否出现过该余数，如果出现过则开始循环
            if (map.containsKey(numres)) {
                int beg = map.get(numres); //循环体开始的位置
                String part1 = res.substring(0, beg);
                String part2 = res.substring(beg, res.length());
                res = part1 + "(" + part2 + ")";
                return res;

            //继续下除
            map.put(numres, res.length());
            numInt = numres/den;
            res += String.valueOf(numInt);
            numres = (numres%den) * 10;
        }
        return res;
    }
}

class Solution {
public:
    string fractionToDecimal(int numerator, int denominator) {
        if (numerator == 0) return "0";
        if (denominator == 0) return "";
        string res;
        //处理结果是否是负数
        if ((numerator<0)^(denominator<0)) res += "-";
        //将分子分母都转换为正数,先转化为long型，防止取绝对值时溢出
        long num = numerator;
        long den = denominator;
        num = abs(num);
        den = abs(den);
        //整除部分
        res += to_string(num/den);
        //判断是否整除是否有小数部分，没有就返回
        if (num%den==0) return res;
        //处理小数部分
        res += '.';
        unordered_map<int, int> map;
        for (long re=num%den; re; re%=den) {
            if (map.count(re)>0) { //判断是否出现重复元素
                res.insert(map[re], 1, '(');//为重复部分添加括号
                res += ')';
                break;

            //记住该余数当前位置
            map[re] = res.size();
            re *= 10;
            res += to_string(re/den);//将每一位整除部分添加到返回字符串中。
        }
        reurn res;
    }
};
