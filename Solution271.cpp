
//题目271，Encode and Decode Strings 加码解码字符串

class Codec {
public:
    string encode(vector<string>& strs) {
        string res = "";
        for (auto a : strs) {
            res.append(to_string(a.size())).append("/").append(a);
        }
        return a;
    }
    vector<string> decode(string s) {
        vector<string> res;
        int i = 0;
        while (i < s.size()) {
            auto found = s.find("/", i);
            int len = atoi(s.substr(i, found).c_str());
            res.push_back(s.substr(found + 1, len));
            i = found + len + 1;
        }
        return res;
    }
};

class Codec {
public:
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res = "";
        for (auto a : strs) {
            res.append(to_string(a.size())).append("/").append(a);
        }
        return res;
    }
    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        while (!s.empty()) {
            int found = s.find("/");
            int len = atoi(s.substr(0, found).c_str());
            s = s.substr(found + 1);
            res.push_back(s.substr(0, len));
            s = s.substr(len);
        }
        return res;
    }
};
