class Solution {
public:
    int miceAndCheese(vector<int>& reward1, vector<int>& reward2, int k) {
        int n = reward1.size();
        vector<pair<int, int>> difference;
        for (int i = 0; i < n; ++i) {
            difference.push_back({reward1[i] - reward2[i], i});
        }
        sort(difference.begin(), difference.end(), greater<pair<int, int>>());
        int res = 0;
        for (int i = 0; i < n; ++i) {
            if (i < k) {
                res += reward1[difference[i].second];
            }
            else {
                res += reward2[difference[i].second];
            }
        }
        return res;
    }
};