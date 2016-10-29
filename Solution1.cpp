
//题目1，Two Sum 找出给定数组中相加和为target值的数组下标
//题目167，Two Sum II
//题目170，Two Sum III - Data structure design

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> res;
        for (int i=0; i<nums.size(); i++) {
            for (int j=i+1; j<nums.size(); j++) {
                if (nums[i] + nums[j] == target) {
                    res.push_back(i);
                    res.push_back(j);
                    break;
                }
            }
        }
        return res;
    }
};

public class Solution {
    public int[] twoSum(int[] nums, int target) {
        int nums_sorted = new int[nums.length];
        System.arraycopy(nums, 0, nums_sorted, 0, nums.length);
        Arrays.sort(nums_sorted);

        int start = 0;
        int end = nums_sorted.length;
        while (start < end) {
            while (nums_sorted[start] + nums_sorted[--end] > target);
            if (nums_sorted[start] + nums_sorted[end] == target)
                break;
            while (nums_sorted[++start] + nums_sorted[end] < target);
            if (nums_sorted[start] + nums_sorted[end] == target)
                break;
        }

        int ret = new int[2];
        int index = 0;
        int a = nums_sorted[start];
        int b = nums_sorted[end];
        for (int i=0; i<nums.size(); i++) {
            if (nums[i] == a || nums[i] == b) {
                ret[index++] = i;
            }
        }
        return ret;
    }
}

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> res;
        unordered_map<int, int> mapping;

        for (int i=0; i<nums.size(); i++) {
            mapping[nums[i]] = i;
        }

        for (int i=0; i<nums.size(); i++) {
            const int gap = target - nums[i];
            if (mapping.find(gap) != mapping.end() && mapping[gap] > i) {
                res.push_back(i);
                res.push_back(mapping[gap]);
                break;
            }
        }
        return res;
    }
};

class Solution {
public:
    vector<int> twoSum(vector<int> &nums, int target) {
        vector<int> res;
        unordered_map<int, int> mapping;

        for (int i=0; i<nums.size(); i++) {
            mapping[nums[i]] = i;
        }

        for (int i=0; i<nums.size(); i++) {
            const int gap = target - nums[i];
            if (mapping.count(gap) && mapping[gap]!=i) {
                res.push_back(i);
                res.push_back(mapping[gap]));
                break;
            }
        }
        return res;
    }
};
