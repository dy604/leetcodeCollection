
//题目299，Bulls and Cows 公母牛游戏

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        unordered_map<char, int> res;
        vector<bool> tag(secret.size(), false);

        for (auto s : secret) {
            ++res[s];
        }

        for (int i=0; i<secret.size(); i++) {
            if (secret[i] == guess[i]) {
                bulls++;
                --res[secret[i]];
                tag[i] = true;
            }
        }

        for (int i=0; i<guess.size(); i++) {
            if (!tag[i] && res[guess[i]]>0) {
                cows++;
                --res[guess[i]];
            }
        }
        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};

public class Solution {
    public String getHint(String secret, String guess) {
        int bulls = 0;
        int cows = 0;
        int[] nums = new int[10];

        for (int i=0; i<secret.length(); i++) {
            if (secret.charAt(i) == guess.charAt(i)) {
                bulls++;
            } else {
                if (nums[secret.charAt(i)-'0']++ < 0) {
                    cows++;
                }
                if (nums[guess.charAt(i)-'0']-- > 0) {
                    cows++;
                }
            }
        }
        return bulls + "A" + cows + "B";
    }
}

class Solution {
public:
    string getHint(string secret, string guess) {
        int bulls = 0;
        int cows = 0;
        vector<int> sVec(10, 0);
        vector<int> gVec(10, 0);

        for (int i=0; i<secret.size(); i++) {
            char c1 = secret[i];
            char c2 = guess[i];
            if (c1 == c2) {
                bulls++;
            } else {
                sVec[c1-'0']++;
                gVec[c2-'0']++;
            }
        }

        for (int i=0; i<sVec.size(); i++) {
            cows += min(sVec[i], gVec[i]);
        }

        return to_string(bulls) + "A" + to_string(cows) + "B";
    }
};
