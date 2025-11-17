class Solution {
public:
    bool kLengthApart(vector<int>& nums, int k) {
        int now = INT_MAX / 2;
        for (auto& num : nums) {
            if (num == 0) now++;
            else {
                if (now < k) return false;
                now = 0;
            }
        }
        return true;
    }
};
