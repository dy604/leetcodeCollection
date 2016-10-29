
//��Ŀ26��Remove Duplicates from Sorted Array ������������ɾ���ظ�Ԫ��
//��Ŀ80��Remove Duplicates from Sorted Array II

class Solution {
public:
    int removeDuplicates(vector<int> &nums) {
        if (nums.empty()) return 0;
        int index = 0;
        for (int i=1; i<nums.size(); i++) {
            if (nums[index] != nums[i])
                nums[++index] = nums[i];
        }
        return index+1;
    }
};
