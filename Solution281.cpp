
//题目281，Zigzag Iterator 之字形迭代器

class ZigzagIterator {
public:
    ZigzagIterator(vector<int> &v1, vector<int> &v2) {
        v.push_back(v1);
        v.push_back(v2);
    }
    int next() {
        return i<=j ? v[0][i++] : v[1][j++];
    }
    bool hasNext() {
        if (i >= v[0].size()) i = INT_MAX;
        if (j >= v[1].size()) j = INT_MAX;
        return i < v[0].size() || j < v[1].size();
    }
private:
    vector<vector<int>> v;
    int i, j;
};

class ZigzagIterator {
public:
    ZigzagIterator(vector<int> &v1, vector<int> &v2) {
        int n1 = v1.size(), n2 = v2.size(), n = max(n1, n2);
        for (int i=0; i<n; ++i) {
            if (i < n1) v.push_back(v1[i]);
            if (i < n2) v.push_back(v2[i]);
        }
    }
    int next() {
        return v[i++];
    }
    int hasNext() {
        return i < v.size();
    }
private:
    vector<int> v;
    int i = 0;
};

class ZigzagIterator {
public:
    ZigzagIterator(vector<int> &v1, vector<int> &v2) {
        if (!v1.empty()) q.push_back(make_pair(v1.begin(), v1.end()));
        if (!v2.empty()) q.push_back(make_pair(v2.begin(), v2.end()));
    }
    int next() {
        auto it = q.front().first, end = q.front().seond();
        q.pop();
        if (it + 1 != end) q.push(make_pair(it+1, end));
        return *it;
    }
    bool hasNext() {
        return !q.empty();
    }
private:
    queue<pair<vector<int>::iterator, vector<int>::iterator>> q;
};
