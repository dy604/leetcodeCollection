
//题目66，Plus One 加一运算

public class Solution {
    public int[] plusOne(int[] digits) {
        int carry = 1;
        int tmp;
        for (int i=digits.length-1; i>=0; i--) {
            tmp = digits[i];
            digits[i] = (tmp+carry)%10;
            carry = (tmp+carry)/10;
            if (carry == 0) {
                break;
            }
        }
        if (carry == 1) {
            int[] res = new int[digits.length+1];
            System.arraycopy(digits,0,res,1,digits.length);
            res[0] = carry;
            return res;
        } else {
            return digits;
        }
    }
}

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        int carry = 1;
        for (int i=digits.size()-1; i>=0 && carry; i--) {
            int sum = carry + digits[i];
            carry = sum/10;
            digits[i] = sum%10;
        }

        if (carry) {
            digits[0] = 1;
            digits.push_back(0);
        }
        return digits;
    }
};

class Solution {
public:
    vector<int> plusOne(vector<int> &digits) {
        vector<int> res;
        int carry = 1;
        for (int i=digits.size()-1; i>=0; --i) {
            int sum = carry + digits[i];
            res.insert(res.begin(), sum%10);
            carry = sum/10;
        }
        if (carry==1)
            res.insert(res.begin(), 1);
        return res;
    }
};
