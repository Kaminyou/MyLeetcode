class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        int n = nums.size();
        vector<int> l2r(n, 0);
        vector<int> r2l(n, 0);
        
        l2r[0] = nums[0];
        for (int i = 1; i < n; i++) l2r[i] = l2r[i - 1] * nums[i];
        r2l[n - 1] = nums[n - 1];
        for (int i = n - 2; i >= 0; i--) r2l[i] = r2l[i + 1] * nums[i];
        
        vector<int> res(n, 0);
        for (int i = 0; i < n; i++) {
            if (i == 0) res[i] = r2l[i + 1];
            else if (i == n - 1) res[i] = l2r[i - 1];
            else res[i] = l2r[i - 1] * r2l[i + 1];
        }
        return res;
    }
};