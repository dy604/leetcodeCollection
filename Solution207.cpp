
//题目207，Course Schedule 课程清单
//题目210，Course Schedule II

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>(0));//存储有向图
        vector<int> in(numCourses, 0);//表示每个顶点的入度
        for (auto a : prerequisites) {//初始化有向图以及每个顶点的入度
            graph[a.second].push_back(a.first);
            ++in[a.first];
        }
        queue<int> q;//将所有入度为0的点放入队列中
        for (int i=0; i<numCourses; ++i) {
            if (in[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int t = q.front();
            q.pop();
            for (auto a : graph[t]) {
                --in[a];
                if (in[a] == 0) q.push(a);
            }
        }
        for (int i=0; i<numCourses; ++i) {
            if (in[i] != 0) return false;
        }
        return true;
    }
};

class Solution {
public:
    bool canFinish(int numCourses, vector<pair<int, int>> &prerequisites) {
        vector<vector<int>> graph(numCourses, vector<int>(0));//存储有向图
        vector<int> visit(numCourses, 0);//记录访问状态
        for (auto a : prerequisites) {//初始化有向图
            graph[a.second].push_back(a.first);
        }
        for (int i=0; i<numCourses; ++i) {
            if (!canFinishDFS(graph, visit, i)) return false;
        }
        return true;
    }
    bool canFinishDFS(vector<vector<int>> &graph, vector<int> &visit, int i) {
        if (visit[i] == -1) return false;
        if (visit[i] == 1) return true;
        visit[i] = -1;
        for (auto a : graph[i]) {
            if (!canFinishDFS(graph, visit, a)) return false;
        }
        visit[i] = 1;
        return true;
    }
};
