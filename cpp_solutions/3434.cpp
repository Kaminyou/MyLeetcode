class Solution {
public:
    int maxFrequency(vector<int>& nums, int k) {
        int ks = 0;
        for (auto& num : nums) {
            if (num == k) ks++;
        }

        int res = ks;
        for (int i = 1; i <= 50; ++i) {
            if (i == k) continue;
            int cnt = 0;
            for (auto& num : nums) {
                if (num == k) cnt--;
                if (num == i) cnt++;
                if (cnt < 0) cnt = 0;
                res = max(res, ks + cnt);
            }
        }
        return res;
    }
};
