class Solution {
public:
    const long long mod = 1e9 + 7;
    long long dp(int n, string& target, int currIdx, int wordIdx, vector<vector<long long>>& memo, vector<vector<int>>& counts) {
        if (currIdx == target.size()) {
            return 1;
        }
        if (wordIdx >= n) return 0;
        if (memo[currIdx][wordIdx] != -1) return memo[currIdx][wordIdx];
        long long res = 0;
        // skip
        res += dp(n, target, currIdx, wordIdx + 1, memo, counts);
        if (counts[target[currIdx] - 'a'][wordIdx] > 0) {
            res += counts[target[currIdx] - 'a'][wordIdx] * dp(n, target, currIdx + 1, wordIdx + 1, memo, counts);
        }
        return memo[currIdx][wordIdx] = (res % mod);
    }
    int numWays(vector<string>& words, string target) {
        vector<vector<long long>> memo(target.size(), vector<long long>(words[0].size(), -1));
        // char, position
        vector<vector<int>> counts(26, vector<int>(words[0].size(), 0));
        for (auto& word : words) {
            for (int i = 0; i < word.size(); ++i) {
                counts[word[i] - 'a'][i]++;
            }
        }
        long long res = dp(words[0].size(), target, 0, 0, memo, counts);
        return res;
    }
};