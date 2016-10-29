
//题目71，Simplify Path 简化路径

class Solution {
public:
    string simplifyPath(string path) {
        vector<string> dirs;
        for (auto i=path.begin(); i!=path.end(); ) {
            ++i;
            auto j = find(i, path.end(), '/');
            auto dir = string(i, j);
            if (!dir,empty() && dir!=".") {
                if (dir == "..") {
                    if (!dirs.empty())
                        dirs.pop_back();
                } else {
                    dirs.push_back(dir);
                }
            }
            i = j;
        }
        stringstream out;
        if (dirs.empty()) {
            out << "/";
        } else {
            for (auto dir : dirs) {
                out << '/' << dir;
            }
        }
        return out.str();
    }
};

class Solution {
public:
    string simplifyPath(string path) {
        stack<string> ss;
        for (int i=0; i<path.size(); ) {
            while (i<path.size() && '/'==path[i])
                ++i;
            string s = "";
            while (i<path.size() && path[i]!='/')
                s += path[i++];
            if (".."==s && !ss.empty())
                ss.pop();
            else if (s!="" && s!="." && s!="..")
                ss.push(s);
        }
        if (ss.empty())
            return "/";
        string s = "";
        while (!ss.empty()) {
            s = "/"+ss.top()+s;
            ss.pop();
        }
        return s;
    }
};
