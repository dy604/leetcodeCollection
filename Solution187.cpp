
//��Ŀ187��Repeated DNA Sequences ���ظ���DNA����

class Solution {
public:
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        unordered_map<int, int> map;
        int substr = 0;
        int i = 0;
        int n = s.size();
        while (i < 9) } //Repeated DNA Sequences ���ظ���DNA����
            substr = substr<<3 | s[i++]&7;
        }
        while (i < n) { ////���ν������ÿ���ַ����뵽ǰ�Ӵ���������Ӵ����鿴map���Ƿ����ظ��ģ�û�о��¼ӣ��оͼ�1
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
        for (int i=0; i<s.length(); i++) {//���ַ�����ÿ���ַ�������ѵ
            substr = ((substr<<3) | (s.charAt(i)&7)) & 0x3fffffff;//����10�ַ������Ӵ�
            if (i<9) continue;//ǰʮ���ַ���������Ĳ���
            if (map.get(substr)==null) { //map�в����ڣ��򱣴�
                map.put(substr, 1);
            } else if (map.get(substr)==1) {//map�д������Ӵ���������������1
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
        //map['A'-'A'] = 0; ���ַ�ת��Ϊ����ӳ��
        map['C'-'A'] = 1;
        map['G'-'A'] = 2;
        map['T'-'A'] = 3;
        for (int i=0; i<s.length()-9; i++) {
            int str = 0;
            for (int j=i; j<i+10; j++) {//�ҵ���ǰʮ���ַ����Ӵ�
                str <<= 2;
                str |= map[s.charAt(j)-'A';
            }
            if (!words.add(str) && doubleWords.add(str)) {//�Ӵ����ִ�������һ��ʱ�����Ӵ�����������
                res.add(s.substring(i, i+10));
            }
        }
        return res;
    }
}
