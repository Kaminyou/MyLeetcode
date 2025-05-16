class Solution {
public:
    int distance(string& w1, string& w2) {
        int m = w1.size();
        int cnt = 0;
        for (int i = 0; i < m; ++i) {
            if (w1[i] != w2[i]) cnt++;
        }
        return cnt;
    }
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {
        int n = words.size();
        vector<int> dp(n, 1);
        vector<int> trace(n, -1);
        int res = 1;
        int maxIndex = 0;
        for (int i = 1; i < n; ++i) {
            for (int j = 0; j < i; ++j) {
                // check if words[i] can be previous to words[j]
                if (words[i].size() != words[j].size()) continue;
                if (groups[i] == groups[j]) continue;
                if (distance(words[i], words[j]) != 1) continue;
                if (dp[j] + 1 > dp[i]) {
                    dp[i] = dp[j] + 1;
                    trace[i] = j;
                    if (dp[i] > res) {
                        res = dp[i];
                        maxIndex = i;
                    }
                }                
            }
        }
        vector<string> v;
        while (maxIndex != -1) {
            v.push_back(words[maxIndex]);
            maxIndex = trace[maxIndex];
        }
        reverse(v.begin(), v.end());
        return v;
    }
};

