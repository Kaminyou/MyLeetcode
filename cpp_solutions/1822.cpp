class Solution {
public:
    int arraySign(vector<int>& nums) {
        int curr = 1;
        for (auto num : nums) {
            if (num == 0) return 0;
            if (num < 0) curr *= -1;
        }
        return curr;
    }
};