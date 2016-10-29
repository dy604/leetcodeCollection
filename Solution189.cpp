
//题目189，Rotate Array 旋转数组

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        int n = nums.size();
        vector<int> res(n);
        if (n==0 || k<=0)
            return ;
        for (int i=0; i<n; i++) { //写出
            res[i] = nums[i];
        }
        for (int i=0; i<n; i++) { //写入
            nums[(i+k)%n] = res[i];
        }
    }
};

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        int n = nums.size();
        if (n==0 || k<=0)
            return ;
        int cur = 0;
        int tmp = 0;
        int numRotated = nums[0];
        int count = 0;
        int start = 0;
        while (count < n) {
            do {
                tmp = nums[(cur+k)%n];
                nums[(cur+k)%n] = numRotated;
                numRotated = tmp;
                cur = (cur+k)%n;
                count++;
            } while (cur != start);
            start++;
            cur = start;
            numRotated = nums[cur];
        }
    }
};

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        int n = nums.size();
        k = k%n;
        reverse(nums.begin(), nums.begin()+n-k);
        reverse(nums.begin()+n-k, nums.end());
        reverse(nums.begin(), nums.end());
    }
};

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        if (nums.empty() || (k%=nums.size())==0) return;
        int n = nums.size();
        for (int i=0; i<n-k; ++i) {
            nums.push_back(nums[0]);
            nums.erase(nums.begin());
        }
    }
};

class Solution {
public:
    void rotate(vector<int> &nums, int k) {
        if (nums.empty()) return;
        int n = nums.size(), start = 0;
        while (n && (k %= n)) {
            for (int i=0; i<k; ++i) {
                swap(nums[i+start], nums[n-k+i+start]);
            }
            n -= k;
            start += k;
        }
    }
};
