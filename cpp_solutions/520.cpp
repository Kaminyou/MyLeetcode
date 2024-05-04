class Solution {
public:
    bool detectCapitalUse(string word) {
        int n = word.size();
        if (n == 1) return true;
        bool firstCap = false;
        if (word[0] >= 'A' && word[0] <= 'Z') firstCap = true;
        int capCnt = 0;
        for (auto& c : word) {
            if (c >= 'A' && c <= 'Z') capCnt++;
        }
        if (capCnt == n || capCnt == 0) return true;
        if (capCnt == 1 && firstCap) return true;
        return false;
    }
};