
//题目239，Sliding Window Maximum 滑动窗口最大值

class Solution {
public:
    vector<int> maxSlidingWindow(vector<int>& nums, int k) {
        vector<int> res;
        deque<int> q;//双向队列
        for (int i=0; i<nums.size(); ++i) {
            if (!q.empty() && q.front()==i-k) q.pop_front(); //维持窗口大小为k
            while (!q.empty() && nums[q.back()]<nums[i]) q.pop_back(); //将双向队列中比当前值小的都弹出
            q.push_back(i);
            if (i>=k-1) res.push_back(nums[q.front()]);
        }
        return res;
    }
};
