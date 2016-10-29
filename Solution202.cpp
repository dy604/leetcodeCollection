
//题目202，Happy Number 快乐数

//主要考虑是否会有循环产生,快乐数最终为1，不快乐数最终为4的循环
class Solution {
public:
    bool isHappy(int n) {
        int num = 0;
        unordered_map<int, bool> table;
        table[n] = 1;
        while (n!=1) {
            while (n) {
                num += (n%10) * (n%10);
                n /= 10;
            }
            if (table[num]) {
                break;
            } else {
                table[num] = 1;
                n = num;
                num = 0;
            }
        }
        return 1 == n;
    }
};

class Solution {
public:
    bool isHappy(int n) {
        int slow, fast;
        slow = fast = n;
        do {
            slow = compute(slow);
            fast = compute(fast);
            fast = compute(fast);
        }while (slow != fast);
        return 1==slow;
    }
private:
    int compute(int n) {
        int num = 0;
        while (n) {
            num += (n%10) * (n%10);
            n /= 10;
        }
        return num;
    }
};

class Solution {
public:
    bool isHappy(int n) {
        int num = 0;
        while (n!=1 && n!=4) {
            while (n) {
                num += (n%10) * (n%10);
                n /= 10;
            }
            n = num;
            num = 0;
        }
        return 1==n;
    }
};
