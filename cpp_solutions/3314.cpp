class Solution {
public:
    vector<int> minBitwiseArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, -1);
        for (int i = 0; i < n; ++i) {
            int num = nums[i];
            for (int j = 0; j <= num; ++j) {
                if ((j | (j + 1)) == num) {
                    res[i] = j;
                    break;
                }
            }
        }
        return res;
    }
};
