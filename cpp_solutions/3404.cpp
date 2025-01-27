class Solution {
public:
    int getKey(int a, int b) {
        int gcd = __gcd(a, b);
        int aa = a / gcd;
        int bb = b / gcd;
        return (aa << 12) + bb;
    }
    long long numberOfSubsequences(vector<int>& nums) {
        unordered_map<int, vector<int>> mp;
        int n = nums.size();
        for (int s = 0; s < n; ++s) {
            for (int r = s + 2; r < n; ++r) {
                mp[getKey(nums[s], nums[r])].push_back(s);
            }
        }
        for (auto& [k, v] : mp) sort(v.begin(), v.end());
        long long res = 0;
        for (int p = 0; p < n; ++p) {
            for (int q = p + 2; q < n; ++q) {
                int key = getKey(nums[q], nums[p]);
                auto iter = lower_bound(mp[key].begin(), mp[key].end(), q + 2);
                res += mp[key].end() - iter;
            }
        }
        return res;
    }
};

// nums[p] * nums[r] == nums[q] * nums[s]
// nums[p] / nums[q] == nums[s] / nums[r]
