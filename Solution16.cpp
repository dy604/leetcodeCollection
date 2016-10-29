
//��Ŀ16��3Sum Closet���Ӹ����������ҳ��������ĺ��������target��ӽ�

class Solution {
public:
    int threeSumClosest(vector<int> &nums, int target) {
        int res = 0;
        int curMin = INT_MAX;
        sort(nums.begin(), nums.end());
        for (int i=0; i<nums.size()-2; i++) {
            int j = i+1;
            int k = nums.size()-1;
            while (j < k) {
                const int sum = nums[i]+nums[j]+nums[k];
                const int gap = abs(sum - target);
                if (gap < curMin) {
                    res = sum;
                    curMin = gap;
                }
                if (sum < target) {
                    j++;
                } else {
                    k--;
                }
            }
        }
        return res;
    }
};
