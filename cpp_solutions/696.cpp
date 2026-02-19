class Solution {
public:
    int countBinarySubstrings(string s) {
        vector<int> cnts;
        int cnt = 0;
        char target = s[0];
        for (auto& c : s) {
            if (c != target) {
                target = c;
                cnts.push_back(cnt);
                cnt = 1;
            }
            else cnt++;
        }
        cnts.push_back(cnt);
        int n = cnts.size();
        int res = 0;
        for (int i = 0; i < n - 1; i++) {
            res += min(cnts[i], cnts[i + 1]);
        }
        return res;
    }
};

