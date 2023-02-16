class Solution {
public:
    bool isVowel(char c) {
        if (c == 'a') return true;
        if (c == 'e') return true;
        if (c == 'i') return true;
        if (c == 'o') return true;
        if (c == 'u') return true;
        return false;
    }
    bool isValid(string& word) {
        int m = word.size();
        if (isVowel(word[0]) && isVowel(word[m - 1])) return true;
        return false;
    }
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        int n = words.size();
        int m = queries.size();
        vector<int> prefixSum(n + 1, 0);
        int count = 0;
        for (int i = 0; i < n; ++i) {
            count += isValid(words[i]);
            prefixSum[i + 1] = count;
        }
        vector<int> res(m, 0);
        for (int i = 0; i < m; ++i) {
            res[i] = prefixSum[queries[i][1] + 1] - prefixSum[queries[i][0]];
        }
        return res;
    }
};