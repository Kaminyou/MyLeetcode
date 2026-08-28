class Solution {
public:
    string buildPalindromic(string half, char middle) {
        string anotherHalf = half;
        reverse(anotherHalf.begin(), anotherHalf.end());
        if (middle == '#') return half + anotherHalf;
        half.push_back(middle);
        return half + anotherHalf;
    }
    string lexPalindromicPermutation(string s, string target) {
        vector<int> counts(26, 0);
        for (auto& c : s) {
            counts[c - 'a']++;
        }
        // check if any palindromic
        int cntOdd = 0;
        int cntEven = 0;
        for (int i = 0; i < 26; ++i) {
            if (counts[i] == 0) continue;
            if (counts[i] & 1) cntOdd++;
            else cntEven++;
        }
        if (cntOdd > 1) return "";
        char oddChar = '#';
        for (int i = 0; i < 26; ++i) {
            if (counts[i] & 1) oddChar = 'a' + i;
            counts[i] /= 2;
        }

        // edge case
        string res = "";
        for (int i = 25; i >= 0; --i) {
            for (int j = 0; j < counts[i]; ++j) {
                res.push_back(i + 'a');
            }
        }
        res = buildPalindromic(res, oddChar);
        if (res <= target) return "";
        int n = target.size() / 2;
        for (int i = 0; i < n; ++i) {
            // before i: same
            // i: greater
            // after i: small to larget
            string tmp = "";
            vector<int> temp = counts;
            bool okay = true;
            for (int j = 0; j < i; ++j) {
                if (temp[target[j] - 'a'] == 0) {
                    okay = false;
                    break;
                }
                temp[target[j] - 'a']--;
                tmp.push_back(target[j]);
            }
            if (!okay) continue;
            int curr = target[i] - 'a';
            okay = false;
            for (int k = curr + 1; k < 26; ++k) {
                if (temp[k] > 0) {
                    temp[k]--;
                    okay = true;
                    tmp.push_back(k + 'a');
                    break;
                }
            }
            if (!okay) continue;
            for (int k = 0; k < 26; ++k) {
                for (int l = 0; l < temp[k]; ++l) {
                    tmp.push_back(k + 'a');
                }
            }
            tmp = buildPalindromic(tmp, oddChar);
            if (tmp < res) res = tmp;
        }
        // all same
        string tmp = "";
        vector<int> temp = counts;
        bool okay = true;
        for (int j = 0; j < n; ++j) {
            if (temp[target[j] - 'a'] == 0) {
                okay = false;
                break;
            }
            temp[target[j] - 'a']--;
            tmp.push_back(target[j]);
        }
        tmp = buildPalindromic(tmp, oddChar);
        if (okay && tmp > target && tmp < res) res = tmp;
        return res;
    }
};
