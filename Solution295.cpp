
//题目295，Find Median from Data Stream 找出数据流的中位数

/**使用大小堆解决，大堆保存右半段教大的数字，小堆保存左半段较小的数字。
堆的保存方式是由大到小。大堆里面的数据是从小到大，这样取第一个数来计算
中位数方便，所以大堆里面的数先取反再存，这样由大到小存下来的顺序就是实
际上我们想要的从小到大的顺序。
当大堆和小堆中的数字一样多时，我们取出大堆小堆的首元素求平均值，当小元
素多时，取小堆首元素为中位数。
*/

class MedianFinder {
public:
    void addNum(int num) {
        small.push(num); //由大到小，自动排序
        large.push(-small.top());
        small.pop();
        if (small.size() < large.size()) {
            small.push(-large.top());
            large.pop();
        }
    }
    double findMedian() {
        return small.size() > large.size() ? small.top() : 0.5*(small.top() - large.top());
    }
private:
    priority_queue<long> small, large;//利用priority_queue实现堆
};

class MedianFinder {
public:
    void addNum(int num) {
        small.insert(num);
        large.insert(-*small.begin());
        small.erase(small.begin());
        if (small.size() < large.size()) {
            small.insert(-*large.begin());
            large.erase(large.begin());
        }
    }
    double findMedian() {
        return small.size() > large.size() ? *small.begin() : 0.5*(*small.begin() - *large.begin());
    }
private:
    multiset<long> small, large;
};
