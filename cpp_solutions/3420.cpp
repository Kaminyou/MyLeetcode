class Solution {
public:
    long long countNonDecreasingSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        deque<pair<long long, long long>> dq; // {val, cnt}
        int r = n - 1;
        long long res = 0;
        long long cost = 0;
        for (int l = r; l >= 0; --l) {
            long long val = nums[l];
            long long cnt = 1;
            while (!dq.empty() && dq.front().first <= val) {
                auto [_val, _cnt] = dq.front();
                dq.pop_front();
                cnt += _cnt;
                cost += (val - _val) * _cnt;
            }
            dq.push_front({val, cnt});
            while (cost > k) {
                auto& [_val, _cnt] = dq.back();
                cost -= (_val - nums[r]);
                r--;
                _cnt--;
                if (_cnt == 0) dq.pop_back();
            }
            res += (r - l + 1);
        }
        return res;

    }
};
