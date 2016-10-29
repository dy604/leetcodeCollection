
//题目167，Two Sum II - Input array is sorted 两数之和之二 - 输入数组有序
//题目1，Two Sum
//题目170，Two Sum III - Data structure design

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        for (int i=0; i<numbers.size(); ++i) {
            int t = target - numbers[i], left = i+1, right = numbers.size()-1;
            while (left < right) {
                int mid = left + (right-left)/2;
                if (numbers[mid]==t) return {i+1, mid+1};
                else if (numbers[mid]<t) left = mid+1;
                else right = mid;
            }
        }
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int> &numbers, int target) {
        int l = 0, r = numbers.size()-1;
        while (l < r) {
            int sum = numbers[l] + numbers[r];
            if (sum == target) return {l+1, r+1};
            else if (sum < target) ++l;
            else --r;
        }
        return {};
    }
};
