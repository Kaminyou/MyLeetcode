class Solution {
public:
    int numEquivDominoPairs(vector<vector<int>>& dominoes) {
        unordered_map<int, int> mp;
        for (auto& domino : dominoes) {
            int a = domino[0];
            int b = domino[1];
            if (a > b) swap(a, b);
            // a <= b
            int key = (a << 4) + b;
            mp[key]++;
        }
        int res = 0;
        for (auto& [k, v] : mp) {
            res += (v * (v - 1)) / 2;
        }
        return res;
    }
};
