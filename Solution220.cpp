
//题目220，Contains Duplicate III 包含重复值之三
//题目217，Contains Duplicate
//题目219，Contains Duplicate II

class Solution {
public:
    bool containsNearbyAlmostDuplicate(vector<int> &nums, int k, int t) {
        map<int, int> m;
        int j = 0;
        for (int i=0; i<nums.size(); ++i) {
            //维持一个大小为k的窗口，大于该窗口时，擦除掉第一个值
            if (i-j>k && m[nums[j]]==j) m.erase(nums[j++]);
            //通过m.lower_bound(nums[i] - t)找到在map中刚好比nums[i] - t大一点儿的值的下标
            auto a = m.lower_bound(nums[i] - t);
            //满足条件，返回true
            if (a!=m.end() && abs(a->first-nums[i])<t) return true;
            m[nums[i]] = i;
        }
    }
};

//使用桶排序
public class Solution {
    public boolean containsNearbyAlmostDuplicate(int[] nums, int k, int t) {
        if (k<1 || t<0) return false;
        Map<Long, Long> map = new HashMap<>();
        for (int i=0; i<nums.length; i++) {
            long remappedNum = (long) nums[i] - Integer.MIN_VALUE;
            long bucket = remappedNum/((long)t + 1);
            if (map.containsKey(bucket)
                || (map.containsKey(bucket-1) && remappedNum-map.get(bucket-1)<=t)
                || (map.containsKey(bucket+1) && map.get(bucket+1)-remappedNum<=t))
                return true;
            if (map.entrySet().size() >= k) {
                long lastBucket = ((long) nums[i-k]-Integer.MIN_VALUE)/((long)t+1);
                map.remove(lastBucket);
            }
            map.put(bucket, remappedNum);
        }
        return false;
    }
}
