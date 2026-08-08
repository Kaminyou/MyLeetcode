class Solution {
public:
    vector<int> validSequence(string word1, string word2) {
        int m = word1.size();
        int n = word2.size();
        vector<int> suffix(m + 1, 0);
        int cnt = 0;
        int j = n - 1;
        for (int i = m - 1; i >= 0; --i) {
            if (j >= 0 && word1[i] == word2[j]) {
                cnt++;
                j--;
            }
            suffix[i] = cnt;
        }
        vector<int> res;
        bool flag = false;
        j = 0;
        for (int i = 0; i < m && j < n; ++i) {
            if (word1[i] == word2[j]) {
                res.push_back(i);
                j++;
            }
            else if (!flag && suffix[i + 1] >= n - j - 1) {
                flag = true;
                res.push_back(i);
                j++;
            }
        }
        if (j != n) return {};
        return res;
    }
};
