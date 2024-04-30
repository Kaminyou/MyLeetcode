class Solution {
public:
    long long wonderfulSubstrings(string word) {
        long long res = 0;
        unordered_map<int, int> mask2cnt;
        int bit = 0;
        for (auto& c : word) {
            int bitLoc = c - 'a';
            bit ^= (1 << bitLoc);

            // current
            int cnt = __builtin_popcount(bit);
            if (cnt == 0 || cnt == 1) res++;

            // compare with previous ones
            // case 1: difference by 1
            for (int i = 0; i < 10; ++i) {
                int temp = bit ^ (1 << i);
                res += mask2cnt[temp];
            }
            // case 2: difference by 0
            res += mask2cnt[bit];

            // hash
            mask2cnt[bit]++;
        }
        return res;
    }
};
