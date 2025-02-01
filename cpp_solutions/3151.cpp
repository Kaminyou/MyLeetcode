class Solution {
public:
    bool isArraySpecial(vector<int>& nums) {
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            int a = nums[i] & 1;
            int b = nums[i + 1] & 1;
            if (a ^ b == 0) return false;
        }
        return true;
    }
};
