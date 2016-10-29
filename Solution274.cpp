
//题目274，H-Index 求H指数
//题目275，H-Index II

public class Solution {
    public int hIndex(int[] citations) {
        int length = citations.length;
        if (length == 0)
            return 0;
        int[] index = new int[length+1];
        for (int i=0; i<length; i++) {//将引用次数作为下标，对相同引用次数的计数。
            if (citations[i] > length) {
                index[length] += 1;
            } else {
                index[citations[i]] += 1;
            }
        }
        int count = 0;
        for (int i=length; i>=0; i--) {
            count = count + index[i]; //统计大于序号的文章数
            if (count >= i) {//如果文章数大于排序序号时，返回H值
                return i;
            }
        }
        return 0;
    }
}

public class Solution {
    public int hIndex(int[] citations) {
        Arrays.sort(citations);
        int len = citations.length;
        if (len == 0)
            return 0;
        for (int i=0; i<len; i++) {
            if (citations[i] >= len-i) {
                return len-i;
            }
        }
        return 0;
    }
}

class Solution {
public:
    int hIndex(vector<int>& citations) {
        sort(citations.begin(), citations.end(), greater<int>());
        for (int i=0; i<citations.size(); ++i) {
            if (i >= citations[i]) return i;
        }
        return citations.size();
    }
};
