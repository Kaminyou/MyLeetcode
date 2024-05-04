class Solution {
public:
    int maxProduct(vector<string>& words) {
        unordered_map<int, int> mp;
        for (auto word : words) {
            int bitmask = 0;
            for (auto c : word) {
                bitmask |= 1 << (c - 'a');
            }
            mp[bitmask] = max(mp[bitmask], (int)word.size());
        }
        int res = 0;
        for (auto element1 : mp) {
            for (auto element2 : mp) {
                if (!(element1.first & element2.first)) {
                    res = max(res, element1.second * element2.second);
                }
            }
        }
        return res;
    }
};