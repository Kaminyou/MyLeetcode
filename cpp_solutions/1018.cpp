class Solution {
public:
    vector<bool> prefixesDivBy5(vector<int>& nums) {
        int n = nums.size();
        vector<bool> res(n, false);
        int now = 0;
        for (int i = 0; i < n; ++i) {
            now <<= 1;
            now += nums[i];
            now %= 10;
            if (now == 0 || now == 5) res[i] = true;
        }
        return res;
    }
};

