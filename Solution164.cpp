
//题目164，Maximum Gap 求最大间距

//桶排序
class Solution {
public:
    int maximumGap(vector<int> &nums) {
        if (nums.size() < 2) return 0;
        int n = nums.size();
        int minN = nums[0];
        int maxN = nums[0];
        for (int i=1; i<n; ++i) {
            maxN = max(maxN, nums[i]);
            minN = min(minN, nums[i]);
        }
        int len = (maxN-minN)/n + 1; //每个桶的容量
        int bucketNum = (maxN-minN)/len + 1; //桶的数量
        vector<int> bucketMin(bucketNum, INT_MAX); //初始化为最大值，记录每个桶中的最小值
        vector<int> bucketMax(bucketNum, INT_MIN); //初始化为最小值，记录每个桶中的最大值
        for (int i=0; i<n; ++i) {
            int Idx = (nums[i] - minN/len);
            bucketMin[Idx] = min(bucketMin[Idx], nums[i]);
            bucketMax[Idx] = max(bucketMax[Idx], nums[i]);
        }
        int res = 0;
        int pre = 0;
        for (int i=1; i<bucketNum; ++i) {
            if (bucketMin[i]==INT_MAX || bucketMax[i]==INT_MIN)
                continue;
            res = max(res, bucketMin[i]-bucketMax[pre]);
            pre = i;
        }
        return res;
    }
};
