
//题目215，Kth Largest Element in an Array 数组中第k大的数字

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        int len = nums.size();
        sort(nums.begin(), nums.end());
        return nums[len-k];
    }
};

//使用快速排序的思想
class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        int left = 0, right = nums.size()-1;
        while (true) {
            int pos = partition(nums, left, right);
            if (pos == k-1)
                return nums[pos];
            if (pos > k-1)//说明目标值在数组左部分
                right = pos - 1;
            else//说明目标值在数组右部分
                left = pos + 1;
        }
    }
    //以nums数组第一个值作为分割点，大于该值的在数组左边，小于的部分在数组右边
    int partition(vector<int> &nums, int left, int right) {
        int pivot = nums[left];
        int l = left + 1, r = right;
        while (l < r) {
            if (nums[l] < pivot && nums[r] > pivot)
                swap(nums[l++], nums[r--]);
            if (nums[l] >= pivot)
                l++;
            if (nums[r] <= pivot)
                r--;
        }
        swap(nums[left], nums[r]);
        return r;//返回该值的位置
    }
};

//使用堆排序的思想
class Solution {
private:
    int heap_size;
public:
    inline int left(int idx) {
        return (idx << 1) + 1;
    }
    inline int right(int idx) {
        return (idx << 1) + 2;
    }
    void max_heapify(vector<int> &nums, int idx) {
        int largest = idx;
        int l = left(idx), r = right(idx);
        if (l<heap_size && nums[l]>nums[largest]) largest = l;
        if (r<heap_size && nums[r]>nums[largest]) largest = r;
        if (largest != idx) {
            swap(nums[idx], nums[largest]);
            max_heapify(nums, largest);
        }
    }
    void build_max_heap(vector<int> &nums) {
        heap_size = nums.size();
        for (int i=(heap_size>>1)-1; i>=0; i--)
            max_heapify(nums, i);
    }
    int findKthLargest(vector<int> &nums, int k) {
        build_max_heap(nums);
        for (int i=0; i<k; i++) {
            swap(nums[0], nums[heap_size-1]);
            heap_size--;
            max_heapify(nums, 0);
        }
        return nums[heap_size];
    }
};

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        priority_queue<int> pq(nums.begin(), nums.end());
        for (int i=0; i<k-1; i++)
            pq.pop();
        return pq.top();
    }
};

class Solution {
public:
    int findKthLargest(vector<int> &nums, int k) {
        multiset<int> mset;
        int n = nums.size();
        for (int i=0; i<n; i++) {
            mset.insert(nums[i]);
            if (mset.size() > k) {
                mset.erase(mset.begin());
            }
        }
        return *mset.begin();
    }
};
