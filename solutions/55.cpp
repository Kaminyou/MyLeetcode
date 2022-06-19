class Solution {
public:
    bool canJump(vector<int>& nums) {
        int n = nums.size();
        int far = n - 1;
        for (int i = n - 2; i >= 0; --i) {
            if (i + nums[i] >= far) far = i;
        }
        return far == 0;
    }
};