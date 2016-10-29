
//题目125，Valid Palindrome 验证回文字符串

class Solution {
public:
    bool isPalindrome(string s) {
        transform(s.begin(), s.end(), s.begin(), ::tolower());
        auto left = s.begin(), right = prev(s.end());
        while (left < right) {
            if (!::isalnum(*left))
                ++left;
            else if (!::isalnum(*right))
                --right;
            else if (*left != *right)
                return false;
            else {
                left++;
                right--;
            }
        }
        return true;
    }
};

class Solution {
public:
    bool isPalindrome(string s) {
        int left = 0, right = s.size()-1;
        while (left < right) {
            if (!isalnum(s[left]))
                left++;
            else if (!isalnum(s[right]))
                right--;
            else {
                if (tolower(s[left++]) != tolower(s[right--]))
                    return false;
            }
        }
        return true;
    }
};
