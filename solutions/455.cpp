class Solution {
public:
    int findContentChildren(vector<int>& g, vector<int>& s) {
        sort(s.begin(), s.end());
        sort(g.begin(), g.end());
        int indexG = 0;
        int indexS = 0;
        int n = g.size();
        int m = s.size();
        while (indexG < n && indexS < m) {
            if (g[indexG] <= s[indexS]) {
                indexG++;
                indexS++;
            }
            else {
                indexS++;
            }
        }
        return indexG;
    }
};
