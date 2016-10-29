
//题目15，3Sum，从给定数组中找出三个数之后相加为0，满足a ≤ b ≤ c

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        if (nums.size() < 3) return res;

        const int target = 0;
        sort(nums.begin(), nums.end());

        auto last = nums.end();
        for (auto i=nums.begin(); i<last-2; i++) {
            auto j = i+1;
            if (i>nums.begin() && *i==*(i-1))
                continue;
            auto k = last-1;
            while (j < k) {
                if (*i+*j+*k<target) {
                    ++j;
                    while (*j==*(j-1) && j<k)
                        ++j;
                } else if (*i+*j+*k>target) {
                    --k;
                    while (*k==*(k+1) && j<k)
                        --k;
                } else {
                    res.push_back({*i, *j, *k});
                    ++j;
                    --k;
                    while (*j==*(j-1) && *k==*(k+1) && j<k)
                        ++j;
                }
            }
        }
        return res;
    }
};

public class Solution {
    public List<List<Integer>> threeSum(int[] nums) {
        Arrays.sort(nums);
        List<List<Integer>> res = new LinkedList<>();
        for (int i=0; i<nums.length-2; i++) {
            if (i==0 || (i>0 && nums[i]!=nums[i-1])) {
                int j = i+1;
                int k = nums.length-1;
                int target = 0 - nums[i];
                while (j < k) {
                    if (nums[j] + nums[k] == target) {
                        res.add(Arrays.asList(nums[i], nums[j], nums[k]));
                        while (j<k && nums[j]==nums[j+1])
                            j++;
                        while (j<k && nums[k]==nums[k-1])
                            --k;
                        j++;
                        k--;
                    } else if (nums[j]+nums[k]<target) {
                        j++;
                    } else {
                        k--;
                    }
                }
            }
        }
        return res;
    }
}

class Solution {
public:
    vector<vector<int>> threeSum(vector<int> &nums) {
        vector<vector<int>> res;
        sort(nums.begin(), nums.end());
        for (int i=0; i<int(nums.size()-2); ++i) {
            if (i==0 || (i>0 && nums[i]!=nums[i-1])) {
                int left = i+1, right = nums.size()-1; sum = 0 - nums[i];
                while (left < right) {
                    if (nums[left] + nums[right] == sum) {
                        res.push_back({nums[i], nums[j], nums[k]});
                        while (left<right && nums[left]==nums[left+1]) ++left;
                        while (left<right && nums[right]==nums[right-1]) --right;
                        ++left;
                        --right;
                    } else if (nums[left]+nums[right] < sum) ++left;
                    else --right;
                }
            }
        }
        return res;
    }
};
