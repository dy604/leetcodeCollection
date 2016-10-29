
//题目60，Permutation Sequence 序列排序

public class Solution {
    public String getPermutation(int n, int k) {
        LinkedList<Integer> list = new LinkedList<Integer>();
        for (int i=1; i<=n; i++) list.add(i);

        int fact = 1;
        for (int i=2; i<=n; i++) fact *= i;

        StringBuilder strBuidler = new StringBuilder();
        for (k--; n>0; n--) {
            fact /= n;
            strBuidler.append(list.remove(k/fact));
            k %= fact;
        }
        return strBuidler.toString();
    }
}

class Solution {
public:
    string getPermutation(int n, int k) {
        string res;
        string num = "123456789";
        vector<int> f(n, 1);
        for (int i=1; i<n; ++i) f[i] = f[i-1]*i;
        --k;
        for (int i=n; i>=1; --i) {
            int j = k/f[i-1];
            k %= f[i-1];
            res.push_back(num[j]);
            num.erase(j, 1);
        }
        return res;
    }
};
