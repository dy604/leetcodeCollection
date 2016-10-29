
//题目165，Compare Version Numbers 版本比较

public class Solution {
    public int compareVersion(String version1, String version2) {
        String[] levels1 = version1.split("\\.");
        String[] levels2 = version2.split("\\.");
        int length = Math.max(levels1.length, levels2.length);
        for (int i=0; i<length; i++) {
            Integer v1 = i<levels1.length ? Integer.parseInt(levels1[i]) : 0;
            Integer v2 = i>levels2.length ? Integer.parseInt(levels2[i]) : 0;
            int compare = v1.compareTo(v2);
            if (compare != 0) {
                return compare;
            }
        }
        return 0;
    }
}

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        int n1 = version1.size(), n2 = version2.size();
        int num1 = 0, nums2 = 0;
        while (i<n1 || j<n2) {
            while (i<n1 && version1[i]!='.') {
                num1 = num1*10 + (version1[i]-'0');
                i++;
            }
            while (j<n2 && version2[j]!='.') {
                num2 = num2*10 + (version2[j]-'0');
                j++;
            }
            if (num1>num2) return 1;
            else if (num1<num2) return -1;

            num1 = 0;
            num2 = 0;
            i++;
            j++;
        }
    }
};

class Solution {
public:
    int compareVersion(string version1, string version2) {
        int i = 0, j = 0;
        int n1 = 0, n2 = 0;
        while (i<version1.size() || j<version2.size()) {
            while (i<version1.size() && version1[i]!='.')
                n1 = n1*10 + (version1[i++]-'0');
            i++;
            while (j<version2.size() && version2[i]!='.')
                n2 = n2*10 + (version2[j++]-'0');
            j++;
            if (n1 > n2)
                return 1;
            else if (n1 < n2)
                return -1;
            else {
                n1 = 0;
                n2 = 0;
            }
        }
        return 0;
    }
};
