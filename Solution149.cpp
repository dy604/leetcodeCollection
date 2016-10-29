
//题目149，Max Points on a Line 共线点个数

struct Point {
    int x;
    int y;
    Point() : x(0), y(0) {}
    Point(int a, int b) : x(a), y(b) {}
};

class Solution {
public:
    int maxPoint(vector<Point> &points) {
        int res = 0;
        unordered_map<float, int> m; //key表示斜率，表示一条直线，value表示共线的点
        for (int i=0; i<points.size(); ++i) {
            m.clear();
            m[INT_MIN] = 0; //表示两个点重合的情况

            int duplicate = 1; //用来记录重合点的个数
            for (int j=0; j<points.size(); ++j) {
                if (i == j) continue;
                if (points[i].x==points[j].x && points[i].y==points[j].y) {
                    ++duplicate;
                    continue;
                }
                //如果两个点的x坐标相同，则斜率最大，垂直的
                float slope = (points[i].x==points[j].x) ? INT_MAX : (float)(points[j].y-points[i].y)/(points[j].x-points[i].x);
                ++m[slope]; //斜率相同
            }
            for (unordered_map<float, int>::iterator it=m.begin(); it!=m.end(); ++it) {
                res = max(res, it->second+duplicate);
            }
        }
    }
};

class Solution {
public:
    int maxPoints(vector<Point> &points) {
        if (points.size()<3) return points.size();
        int res = 0;
        for (int i=0; i<points.size()-1; i++) {
            for (int j=i+1; j<points.size(); j++) {
                int sign = 0;
                int a, b, c;
                if (points[i].x==points[j].x) sign = 1;
                else {
                    a = points[j].x - points[i].x;
                    b = points[j].y - points[i].y;
                    c = a*points[i].y - b*points[i].x;
                }
                int count = 0;
                for (int k=0; k<points.size(); k++) {
                    if ((0==sign && a*points[k].y==c+b*points[k].x) ||
                        (1==sing && points[k].x==points[j].x))
                            count++;
                }
                if (count > res) res = count;
            }
        }
        return res;
    }
};
