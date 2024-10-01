class Solution {
public:
    bool canArrange(vector<int>& arr, int k) {
        vector<int> mods(k, 0);
        for (int num : arr) {
            mods[((num % k) + 2 * k) % k]++;
        }
        for (int i = 1; i <= k / 2; ++i) {
            if (mods[i] != mods[k - i]) return false;
        }
        if (mods[0] & 1) return false;
        return true;
    }
};

