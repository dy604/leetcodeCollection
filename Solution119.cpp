
//题目119，Pascal's Triangle II 杨辉三角之二
//题目118，Pascal's Triangle

class Solution {
public:
    vector<int> getRow(int rowIndex) {
        vector<int> res(rowIndex+1, 0);
        res[0] = 1;
        for (int i=1; i<rowIndex; i++) {
            for (int j=i; j>=1; j--) {
                res[j] += res[j-1];
            }
        }
    }
};

public class Solution {
    public List<Integer> getRow(int rowIndex) {
        List<Integer> list = new ArrayList<Integer>();
        if (rowIndex < 0)
            return list;

        for (int i=0; i<rowIndex+1; i++) {
            list.add(0,1);
            for (int j=1; j<list.size()-1; j++) {
                list.set(j, list.get(j)+list.get(j+1));
            }
        }
        return list;
    }
}
