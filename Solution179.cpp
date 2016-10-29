
//题目179，Largest Number 最大组合数

class Solution {
public:
    string largestNumber(vector<int> &nums) {
        string res;
        sort(nums.begin(), nums.end(), [](int a, int b) {
            return to_string(a)+to_string(b) > to_string(b)+to_string(a);
        });
        for (int i=0; i<nums.size(); ++i) {
            res += to_string(nums[i]);
        }
        return res[0]=='0' ? "0" : res;
    }
};

class Solution {
public:
    string largestNumber(vector<int> &nums) {
        vector<string> arr;
        for (auto i : nums) {
            arr.push_back(to_string(i));
        }
        sort(begin(arr), end(arr), [](string &s1, string &s2) {
            return s1+s2>s2+s1;
        });
        string res;
        for (auto s : arr) {
            res += s;
        }
        while (res[0]=='0' && res.length()>1)
            res.erase(0, 1);
        return res;
    }
};

public class Solution {
    public String largestNumber(int[] nums) {
        if (nums==null || nums.length==0)
            return "";
        String[] str = new String[nums.length];
        for (int i=0; i<nums.length; i++) {
            str[i] = Integer.toString(nums[i]);
        }
        Arrays.sort(str, new Comparator<String>() {
            public int compare(String s1, String s2) {
                int len1 = s1.length();
                int len2 = s2.length();
                if (len1 > len2) {
                    int res = s1.substring(0, len2).compareTo(s2);
                    return res==0 ? compare(s1.substring(len2), s2) : -res;
                } else if (len1 < len2) {
                    int res = s2.substring(0, len1).compareTo(s1);
                    return res==0 ? compare(s1, s2.substring(len1)) : res;
                } else {
                    return s2.compareTo(s1);
                }
            }
        });
        StringBuidler sb = new StringBuilder();
        for (String s : str) {
            if (sb.length()==0 && s.startsWith("0"))
                continue;
            sb.append(s);
        }
        return sb.length()==0 ? "0" : sb.toString();
    }
}
