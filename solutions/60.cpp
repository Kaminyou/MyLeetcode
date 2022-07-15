class Solution {
public:
    string getPermutation(int n, int k) {
        string res = "";
        string nums = "123456789";
        vector<int> f(n, 1);
        for (int i = 1; i < n; ++i) f[i] = f[i - 1] * i;
        
        k--;
        for (int i = n; i >= 1; --i) {
            int idx = k / f[i - 1];
            k %= f[i - 1];
            res.push_back(nums[idx]);
            nums.erase(idx, 1);
        }
        return res;
    }
};