class Solution {
public:
    vector<int> constructTransformedArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        for (int i = 0; i < n; ++i) {
            int index = i;
            if (nums[i] > 0) {
                index = (((i + nums[i]) % n) + n) % n;
            }
            else if (nums[i] < 0) {
                index = (((i - abs(nums[i])) % n) + n) % n;
            }
            res[i] = nums[index];
        }
        return res;
    }
};
