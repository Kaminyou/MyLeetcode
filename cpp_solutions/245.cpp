class Solution {
public:
    int shortestWordDistance(vector<string>& wordsDict, string word1, string word2) {
        int n = wordsDict.size();
        unordered_map<string, vector<int>> mp;
        for (int i = 0; i < n; ++i) {
            mp[wordsDict[i]].push_back(i);
        }
        
        int res = INT_MAX;
        if (word1 == word2) {
            const vector<int>& v = mp[word1];
            int m = v.size();
            for (int i = 1; i < m; ++i) {
                res = min(res, v[i] - v[i - 1]);
            }
        }
        else {
            const vector<int>& v1 = mp[word1];
            const vector<int>& v2 = mp[word2];
            int idx1 = 0;
            int idx2 = 0;
            while (idx1 < v1.size() && idx2 < v2.size()) {
                res = min(res, abs(v1[idx1] - v2[idx2]));
                if (v1[idx1] > v2[idx2]) idx2++;
                else if (v1[idx1] < v2[idx2]) idx1++;
                else break;
            }
        }
        return res;
    }
};