class Solution {
public:
    unordered_map<int, int> factor(int x) {
        unordered_map<int, int> res;
        for (int i = 2; i <= 1000; ++i) {
            while (x % i == 0) {
                x /= i;
                res[i]++;
            }
        }
        if (x != 1) res[x]++;
        return res;
    }
    int findValidSplit(vector<int>& nums) {
        int n = nums.size();
        unordered_map<int, int> freqBack;
        vector<unordered_map<int, int>> numsHash(n);
        for (int i = 0; i < n; ++i) {
            auto d = factor(nums[i]);
            for (auto [f, c] : d) {
                freqBack[f] += c;
            }
            numsHash[i] = d;
        }
        int dirty = 0;
        auto ori = freqBack;
        for (int i = 0; i <= n - 2; ++i) {
            for (auto [f, c] : numsHash[i]) {
                if (ori[f] == freqBack[f] && freqBack[f] != c) dirty++;
                if (ori[f] != freqBack[f] && freqBack[f] == c) dirty--;
                
                freqBack[f] -= c;
            }
            if (dirty == 0) return i;
        }
        return -1;
    }
};