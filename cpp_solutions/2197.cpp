class Solution {
public:
    vector<int> replaceNonCoprimes(vector<int>& nums) {
        vector<int> res;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int curr = nums[i];
            while (res.size() > 0 && __gcd(res.back(), curr) > 1) {
                curr = res.back() * (curr / __gcd(res.back(), curr));
                res.pop_back();
            }
            res.push_back(curr);
        }
        return res;
    }
};
