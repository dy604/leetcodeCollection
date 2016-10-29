
//题目217，Contains Duplicate 包含重复值
//题目219，Contains Duplicate II
//题目220，Contains Duplicate III

public class Solution {
    public boolean containsDuplicate(int[] nums) {
        Arrays.sort(nums);
        for (int i=1; i<nums.length; i++) {
            if (nums[i] == nums[i-1])
                return true;
        }
        return false;
    }
}

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_set<int> numSet;
        for (int i=0; i<nums.size(); i++) {
            if (numSet.find(nums[i])!=numSet.end()) {
                return true;
            }
            numSet.insert(nums[i]);
        }
        return false;
    }
};

public class Solution {
    public boolean containsDuplicate(int[] nums) {
        final Set<Integer> numSet = new HashSet<Integer>();
        for (int num : nums) {
            if (!numSet.add(num)) {
                return true;
            }
        }
        return false;
    }
}

class Solution {
public:
    bool containsDuplicate(vector<int> &nums) {
        unordered_map<int, int> mapping;
        for (int num : nums) {
            if (++mapping[num] > 1) {
                return true;
            }
        }
        return false;
    }
};

//使用移位操作
public class Solution {
    public boolean containsDuplicate(int[] nums) {
        byte[] mark = new byte[150000];
        for (int i : nums) {
            int j = i/8;
            int k = i%8;
            int check = 1<<k;
            if ((mark[j] & check) != 0)
                return true;
            mark[j] |= check;
        }
        return false;
    }
}
