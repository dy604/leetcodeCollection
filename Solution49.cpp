
//题目49，Group Anagrams 重组字分组

public class Solution {
    public List<List<String>> groupAnagrams(String[] strs) {
        if (strs==null || strs.length==0) {
            return new ArrayList<List<String>>();
        }
        Map<String, List<String>> map = new HashMap<String, List<String>>();
        Arrays.sort(strs);
        for (String s : strs) {
            char[] ca = s.toCharArray();
            Arrays.sort(ca);
            String keyStr = String.valueOf(ca);
            if (!map.containsKey(keyStr)) {
                map.put(keyStr, new ArrayList<String>());
            }
            map.get(keyStr).add(s);
        }
        return new ArrayList<List<String>>(map.values());
    }
}

class Solution {
public:
    vector<vector<string>> groupAnagrams(vector<string> &strs) {
        unordered_map<string, multiset<string>> mapping;
        for (string str : strs) {
            string s = str;
            sort(s.begin(), s.end());
            mapping[s].insert(str);
        }
        vector<vector<int>> res;
        for (auto map : mapping) {
            vector<string> anagram(map.second.begin(), map.second.end());
            res.push_back(anagram);
        }
        return res;
    }
};
