class Solution {
public:
    vector<vector<int>> largeGroupPositions(string s) {
        vector<vector<int>> res;
        int index = 0;
        int n = s.size();
        while (index < n) {
            int start = index;
            while (index + 1 < n && s[start] == s[index + 1]) index++;
            int size = index - start + 1;
            if (size >= 3) res.push_back({start, index});
            index++;
        }
        return res;
    }
};