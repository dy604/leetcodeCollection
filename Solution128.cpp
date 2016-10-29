
//题目128，Longest Consecutive Sequence 求最长连续序列

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        int res;
        unordered_map<int, int> numMap;
        for (int i=0; i<nums.size(); i++)
            numMap[nums[i]] = i;
        for (int i=0; i<nums.size(); i++) {
            int d = nums[i];
            int n = 1;
            numMap.erase(d);
            while (numMap.find(++d)!=numMap.end()) {
                ++n;
                numMap.erase(d);
            }
            d = nums[i];
            while (numMap.find(--d)!=numMap.end()) {
                ++n;
                numMap.erase(d);
            }
            res = max(res, n);
        }
        return res;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_map<int, bool> used;
        for (auto num : nums) used[num] = false;
        int longest = 0;
        for (auto num : nums) {
            if (used[num]) continue;
            int length = 1;
            used[num] = true;
            for (int j=num+1; used.find(j)!=used.end(); ++j) {
                used[j] = true;
                ++length;
            }
            for (int j=num-1; used.find(j)!=used.end(); --j) {
                used[j] = true;
                ++length;
            }
            longest = max(longest, length);
        }
        return longest;
    }
};

class Solution {
public:
    int longestConsecutive(vector<int> &nums) {
        unordered_map<int, int> map;
        int size = nums.size();
        int l = 1;
        for (int i=0; i<size; i++) {
            if (map.find(nums[i])!=map.end()) continue;
            map[nums[i]] = 1;
            if (map.find(nums[i]-1) != map.end()) {
                l = max(l, mergeCluster(map, nums[i]-1, nums[i]));
            }
            if (map.find(nums[i]+1) != map.end()) {
                l = max(l, mergeCluster(map, nums[i], nums[i]+1));
            }
        }
        return size==0 ? 0 : l;
    }
private:
    int mergeCluster(unordered_map<int, int> &map, int left, int right) {
        int upper = right + map[right] - 1;
        int lower = left - map[left] + 1;
        int length = upper - lower + 1;
        map[upper] = length;
        map[lower] = length;
        return length;
    }
};
