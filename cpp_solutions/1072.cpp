class Solution {
public:
    string encode(vector<int>& row) {
        int n = row.size();
        string s = "";
        int start = row[0];
        for (int i = 0; i < n; ++i) {
            if (row[i] == start) s.push_back('0');
            else s.push_back('1');
        }
        return s;
    }
    int maxEqualRowsAfterFlips(vector<vector<int>>& matrix) {
        int m = matrix.size();
        unordered_map<string, int> mp;
        int res = 0;
        for (int i = 0; i < m; ++i) {
            string s = encode(matrix[i]);
            mp[s]++;
            res = max(res, mp[s]);
        }
        return res;
    }
};

