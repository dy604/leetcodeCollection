
//题目210，Course Schedule II 课程清单之二
//题目207，Course Schedule

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites) {
        vector<int> res;
        vector<vector<int>> graph(numCourses, vector<int>(0));
        vector<int> in(numCourses, 0);
        for (auto &a: prerequisites) {
            graph[a.second].push_back(a.first);
            ++in[a.first];
        }
        queue<int> q;
        for (int i=0; i<numCourses; ++i) {
            if (in[i] == 0) q.push(i);
        }
        while (!q.empty()) {
            int t = q.front();
            res.push_back(t);
            q.pop();
            for (auto &a : graph[t]) {
                --in[a];
                if (in[a] == 0) q.push(a);
            }
        }
        if (res.size() != numCourses) res.clear();
        return res;
    }
};

class Solution {
public:
    vector<int> findOrder(int numCourses, vector<pair<int, int>> &prerequisites) {
        vector<unordered_set<int>> graph = make_graph(numCourses, prerequisites);
        vector<int> topsort;
        vector<bool> onpath(numCourses, false), visited(numCourses, false);
        for (int i=0; i<numCourses; i++) {
            if (!visited[i] && dfs(graph, i, onpath, visited, topsort))
                return {};
        }
        reverse(topsort.begin(), topsort.end());
        return topsort;
    }
private:
    //初始化图，生成图
    vector<unordered_set<int>> make_graph(int numCourses, vector<pair<int, int>> &prerequisites) {
        vector<unordered_set<int>> graph(numCourses);
        for (auto pre : prerequisites) {
            graph[pre.second].insert(pre.first);
        }
        return graph;
    }
    //递归完成遍历
    bool dfs(vector<unordered_set<int>> &graph, int node, vector<bool> &onpath, vector<bool> &visited, vector<int> &topsort) {
        if (visited[node]) return false;
        onpath[node] = visited[node] = true;
        for (int neigh : graph[node])
            if (onpath[neigh] || dfs(graph, neigh, onpath, visited, topsort))
                return true;
        topsort.push_back(node);
        return onpath[node] = false;
    }
};
