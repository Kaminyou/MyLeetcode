class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            if (!((sum + nums[i]) & 1)) {
                sum += 1;
            }
        }
        return sum;
    }
};
