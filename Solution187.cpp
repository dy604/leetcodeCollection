
//题目187，Repeated DNA Sequences 求重复的DNA序列

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        unordered_map<int, int> map;
        int substr = 0;
        int i = 0;
        int n = s.size();
        while (i < 9) } //Repeated DNA Sequences 求重复的DNA序列
            substr = substr<<3 | s[i++]&7;
        }
        while (i < n) { ////依次将后面的每个字符加入到前子串中组成新子串，查看map中是否有重复的，没有就新加，有就加1
            if (map[substr = substr<<3 & 0x3FFFFFFF | s[i++]&7]++ == 1) {
                res.push_back(s.substr(i-10, 10));
            }
        }
        return res;
    }
};

public class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        List<String> res = new ArrayList<String>();
        Map<Integer, Integer> map = new HashMap<Integer, Integer>();
        int substr = 0;
        for (int i=0; i<s.length(); i++) {//对字符串中每个字符进行轮训
            substr = ((substr<<3) | (s.charAt(i)&7)) & 0x3fffffff;//保存10字符长的子串
            if (i<9) continue;//前十个字符不做后面的操作
            if (map.get(substr)==null) { //map中不存在，则保存
                map.put(substr, 1);
            } else if (map.get(substr)==1) {//map中存在则将子串放入结果集，并加1
                res.add(s.substring(i-9, i+1));
                map.put(substr, 2);
            }
        }
        return res;
    }
}

public class Solution {
    public List<String> findRepeatedDnaSequences(String s) {
        Set<Integer> words = new HashSet<>();
        Set<Integer> doubleWords = new HashSet<>();
        List<String> res = new ArrayList<>();
        char[] map = new char[26];
        //map['A'-'A'] = 0; 将字符转换为数字映射
        map['C'-'A'] = 1;
        map['G'-'A'] = 2;
        map['T'-'A'] = 3;
        for (int i=0; i<s.length()-9; i++) {
            int str = 0;
            for (int j=i; j<i+10; j++) {//找到当前十个字符的子串
                str <<= 2;
                str |= map[s.charAt(j)-'A';
            }
            if (!words.add(str) && doubleWords.add(str)) {//子串出现次数大于一次时，将子串保存进结果集
                res.add(s.substring(i, i+10));
            }
        }
        return res;
    }
}
