class Solution {
public:
    int maximumXOR(vector<int>& nums) {
        vector<int> counts(32, 0);
        for (auto num : nums) {
            for (int i = 0; i < 32; ++i) {
                if (num & (1 << i)) counts[i]++;
            }
        }
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            if (counts[i] == 0) continue;
            res += (1 << i);
        }
        return res;
    }
};