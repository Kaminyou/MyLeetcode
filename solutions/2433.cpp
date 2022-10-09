class Solution {
public:
    vector<int> findArray(vector<int>& pref) {
        int n = pref.size();
        vector<int> res(n, 0);
        res[0] = pref[0];
        int xorTemp = res[0];
        for (int i = 1; i < n; ++i) {
            res[i] = pref[i] ^ xorTemp;
            xorTemp ^= res[i];
        }
        return res;
    }
};