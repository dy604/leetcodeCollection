
//题目278，First Bad Version 第一个坏版本

public class Solution extends VersionControl {
    public int firstBadVersion(int n) {
        if (n <= 0) return 0;

        if (isBadVersion(1)) {
            return 1;
        } else if (!isBadVersion(n)) {
            return Integer.MAX_VALUE;
        }

        int left = 1;
        int right = n;

        int mid;
        while (true) {
            mid = left + (right - left) / 2;
            if (mid == left) {
                return right;
            }
            if (isBadVersion(mid)) {
                right = mid;
            } else {
                left = mid;
            }
        }
    }
}

bool isBadVersion(int version);

class Solution {
public:
    int firstBadVersion(int n) {
        int left = 1, right = n;
        while (left < right) {
            int mid = left + (right - left)/2;
            if (isBadVersion(mid))
                right = mid;
            else
                left = mid + 1;
        }
        return left;
    }
};
