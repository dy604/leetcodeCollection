
//题目275，H-Index II 求H指数之二
//题目274，H-Index

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int left = 0, len = citations.size(), right = len - 1, mid;
        while (left <= right) {
            mid = (left + right)>>1;
            if (citations[mid] == (len-mid))
                return citations[mid];
            else if (citations[mid] > (len-mid))
                right = mid-1;
            else
                left = mid + 1;
        }
        return len - (right+1);
    }
};

class Solution {
public:
    int hIndex(vector<int>& citations) {
        int left = 0, right = citations.size(), right = len-1, mid;
        while (left <= right) {
            mid = left + (right-left)/2;
            if (citations[mid] >= (len-mid))
                right = mid - 1;
            else
                left = mid + 1;
        }
        return len - left;
    }
};
