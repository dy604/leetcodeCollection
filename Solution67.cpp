
//题目67，Add Binary 二进制数相加

class Solution {
public:
    string addBinary(string a, string b) {
        int flag;
        int anum = a.size()-1;
        int bnum = b.size()-1;
        string c;
        while (anum>=0 && bnum>=0) {
            int num = (a[anum]-'0')+(b[bnum]-'0') + flag;
            flag = num/2;
            num = num%2;
            c = (char)(num+'0')+c;
            anum--;
            bnum--;
        }

        while (anum>=0) {
            int num = (a[anum]-'0') + flag;
            flag = num/2;
            num = num%2;
            c = (char)(num+'0') + c;
            anum--;
        }

        while (bnum>=0) {
            int num = (b[bnum]-'0') + flag;
            flag = num/2;
            num = num%2;
            c = (char)(num+'0') + c;
            bnum--;
        }

        if (flag > 0)
            c = (char)(flag+'0') + c;
        return c;
    }
};

class solution {
public:
    string addBinary(string a, string b) {
        string res = "";
        int m = a.size()-1, n = b.size()-1, carry = 0;
        while (m>=0 || n>=0) {
            int p = m>=0 ? a[m--]-'0' : 0;
            int q = n>=0 ? b[n--]-'0' : 0;
            int sum = p+q+carry;
            res = to_string(sum%2)+res;
            carry = sum/2;
        }
        return carry == 1 ? "1"+res : res;
    }
};
