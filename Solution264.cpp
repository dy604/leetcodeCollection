
//题目264，Ugly Number II 丑陋数之二
//题目263，Ugly Number

public class Solution {
    public int nthUglyNumber(int n) {
        int[] uglyNumbers = new int[n];
        uglyNumbers[0] = 1;
        int idx2 = 0;
        int idx3 = 0;
        int idx5 = 0;
        int counter = 1;
        while (counter < n) {
            int min = minOf(uglyNumbers[idx2]*2, uglyNumbers[idx3]*3, uglyNumbers[idx5]*5);
            if (min == uglyNumbers[idx2]*2) idx2++;
            if (min == uglyNumbers[idx3]*3) idx3++;
            if (min == uglyNumbers[idx5]*5) idx5++;
            uglyNumbers[counter] = min;
            counter++;
        }
        return uglyNumbers[n-1];
    }
    private int minOf(int a, int b, int c) {
        int temp = a<b ? a : b;
        return temp<c ? temp : c;
    }
}

class Solution {
public:
    int nthUglyNumber(int n) {
        if (n <= 0) return false;
        if (n == 1) return true;
        int t2 = 0, t3 = 0, t5 = 0;
        vector<int> k(n);
        k[0] = 1;
        for (int i=1; i<n; i++) {
            k[i] = min(k[t2]*2, k[t3]*3, k[t5]*5);
            if (k[i] == k[t2]*2) t2++;
            if (k[i] == k[t3]*3) t3++;
            if (k[i] == k[t5]*5) t5++;
        }
        return k[n-1];
    }
};
