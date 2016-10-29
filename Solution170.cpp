
//题目170，Two Sum III - Data structure design 两数之和之三 - 数据结构设计
//题目167，Two Sum II
//题目1，Two Sum

class Solution {
public:
    void add(int number) {
        ++m[number];
    }
    bool find(int value) {
        for (auto a : m) {
            int t = value - a.first;
            if ((t!=a.first && m.count(t)) || (t==a.first && a.second>1)) {
                return true;
            }
        }
        return false;
    }
private:
    unordered_map<int, int> m;
};

class Solution {
public:
    void add(int number) {
        s.insert(number);
    }
    bool find(int value) {
        for (auto a : s) {
            int cnt = a==value-a ? 1 : 0;
            if (s.count(value-a) > cnt) {
                return true;
            }
        }
        return false;
    }
private:
    unordered_multiset<int> s;
};
