class Solution {
public:
    vector<int> findSubseq(vector<int>& groups, int cur) {
        int n = groups.size();
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (groups[i] == cur) {
                res.push_back(i);
                cur ^= 1;
            }
        }
        return res;
    }
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<int> v1 = findSubseq(groups, 0);
        vector<int> v2 = findSubseq(groups, 1);
        if (v1.size() < v2.size()) {
            swap(v1, v2);
        }
        vector<string> res;
        int n = v1.size();
        for (int i = 0; i < n; ++i) {
            res.push_back(words[v1[i]]);
        }
        return res;
    }
};
