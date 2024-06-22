class Solution {
public:
    int numberOfSubarrays(vector<int>& nums, int k) {
        unordered_map<int, int> odd2cnt;
        odd2cnt[0] += 1;
        int cnt = 0;
        int res = 0;
        for (auto& num : nums) {
            if (num & 1) cnt += 1;
            res += odd2cnt[cnt - k];
            odd2cnt[cnt] += 1;
        }
        return res;
    }
};

