class Solution {
public:
    string largestPalindromic(string num) {
        vector<int> counts(10, 0);
        for (auto c : num) counts[c - '0']++;
        
        string res;
        for (int i = 9; i >= 1; --i) {
            if (counts[i] >= 2) {
                while (counts[i] > 1) {
                    res.push_back(i + '0');
                    counts[i] -= 2;
                }
            }
        }
        if (res.size() > 0) {
            if (counts[0] >= 2) {
                while (counts[0] > 1) {
                    res.push_back(0 + '0');
                    counts[0] -= 2;
                }
            }
        }
        
        // get the max middle
        int maxMiddle = -1;
        for (int i = 9; i >= 0; --i) {
            if (counts[i] > 0) {
                maxMiddle = i;
                break;
            }
        }
        
        string rev = res;
        reverse(rev.begin(), rev.end());
        if (maxMiddle != -1) {
            res = res + to_string(maxMiddle) + rev;
        }
        else {
            res = res + rev;
        }
        return res;
    }
};
