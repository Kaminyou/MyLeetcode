class Solution {
public:
    bool isIdealPermutation(vector<int>& nums) {
        for (int i = 0; i < nums.size(); ++i) {
            if (abs(i - nums[i]) > 1) return false;
        }
        return true;
    }
};