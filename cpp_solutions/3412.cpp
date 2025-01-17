class Solution {
public:
    long long calculateScore(string s) {
        long long res = 0;
        vector<set<int>> sts(26);
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            int current = s[i] - 'a';
            int reverse = 25 - current;
            if (!sts[reverse].empty()) {
                int j = *sts[reverse].rbegin();
                res += (i - j);
                sts[reverse].erase(sts[reverse].find(j));
            }
            else {
                sts[current].insert(i);
            }
        }
        return res;
    }
};
