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

class Solution {
public:
    bool canJump(vector<int>& nums) {
        int farest = 0;
        int n = nums.size();
        for (int i = 0; i < n - 1; ++i) {
            farest = max(farest, i + nums[i]);
            if (farest < i + 1) return false;
        }
        return true;
    }
};