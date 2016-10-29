
//题目284，Peeking Iterator 顶端迭代器（查看开始的元素）

class Iterator {
    struct Data;
    Data* data;
public:
    Iterator(const vector<int>& nums);
    Iterator(const Iterator& iter);
    virtual ~Iterator();
    int next();
    bool hasNext() const;
};


class PeekingIterator : public Iterator {
public:
    PeekingIterator(const vector<int>& nums) :: Iterator(nums) {
        _flag = false;
    }
    int peek() {
        if (!_flag) {
            _value = Iterator::next();
            _flag = true;
        }
        return _value;
    }
    int next() {
        if (!_flag) return Iterator::next();
        _flag = false;
        return _value;
    }
    bool hasNext() const {
        if (!_flag) return Iterator::next();
        _flag = false;
        return _value;
    }
private:
    int _value;
    int _flag;
};
