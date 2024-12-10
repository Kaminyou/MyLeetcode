class Solution {
public:
    int maximumLength(string s) {
        vector<vector<int>> lens(26);
        int n = s.size();
        int index = 0;
        while (index < n) {
            char c = s[index];
            int start = index;
            while (index + 1 < n && s[index + 1] == c) index++;
            lens[c - 'a'].push_back(index - start + 1);
            index++;
        }
        int res = -1;
        for (auto& len : lens) {
            sort(len.begin(), len.end());
            if (len.size() == 0) continue;
            int m = len.size();
            for (int j = 0; j < m; ++j) {
                if (len[j] >= 3) res = max(res, len[j] - 2);
                if (j + 2 < m) res = max(res, len[j]);
                if (j + 1 < m && len[j + 1] >= len[j] + 1) res = max(res, len[j]);
                if (j + 1 < m && len[j + 1] == len[j] && len[j] > 1) res = max(res, len[j] - 1);
            }
        }
        return res;
    }
};

