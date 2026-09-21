class Solution {
public:
    vector<long long> resultArray(vector<int>& nums, int k) {
        vector<long long> res(k, 0);
        vector<long long> cnt(k, 0);
        vector<long long> cnt2(k, 0);
        for (auto& num : nums) {
            for (int i = 0; i < k; ++i) cnt2[i] = 0;
            // use
            for (int i = 0; i < k; ++i) {
                cnt2[1LL * i * num % k] += cnt[i];
            }
            // not use
            cnt2[num % k]++;

            // update res
            for (int i = 0; i < k; ++i) {
                res[i] += cnt2[i];
            }
            cnt = cnt2;
        }
        return res;
    }
};

