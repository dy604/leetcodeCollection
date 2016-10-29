
//题目219，Contains Duplicate II 包含重复值之二
//题目217，Contains Duplicate
//题目220，Contains Duplicate III

class Solution {
public:
    bool containsNearbyDuplicate(vector<int> &nums, int k) {
        unordered_map<int, int> mapping;
        for (int i=0; i<nums.size(); i++) {
            if (mapping.find(nums[i])!=mapping.end() && i-mapping[nums[i]]<=k)
                return true;
            mapping[nums[i]] = i;
        }
        return false;
    }
};

public class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Set<Integer> res = new HashSet<Integer>();
        for (int i=0; i<nums.length; i++) {
            if (i>k)
                res.remove(nums[i-k+1]);
            if (!res.add(nums[i]))
                return true;
        }
        return false;
    }
}

public class Solution {
    public boolean containsNearbyDuplicate(int[] nums, int k) {
        Set<Integer> appearedNum = new HashSet<Integer>();
        int start = 0, end = 0;
        for (int i=0; i<nums.length; i++) {
            if (!appearedNum.contains(nums[i])) {
                appearedNum.add(nums[i]);
                end++;
            } else return true;
            if (end - start > k) {
                appearedNum.remove(nums[start]);
                start++;
            }
        }
    }
}
