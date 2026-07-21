class Solution {
public:
    int maxActiveSectionsAfterTrade(string s) {
        int curr = s[0] - '0';
        int initial = curr;
        vector<int> counts;
        int totalActive = 0;
        int cnt = 0;
        for (auto& c : s) {
            totalActive += c - '0';
            if (c - '0' == curr) {
                cnt++;
            }
            else {
                counts.push_back(cnt);
                cnt = 1;
                curr ^= 1;
            }
        }
        counts.push_back(cnt);
        int res = totalActive;
        int m = counts.size();
        for (int i = initial; i + 2 < m; i += 2) {
            res = max(res, counts[i] + totalActive + counts[i + 2]);
        }
        return res;
    }
};

