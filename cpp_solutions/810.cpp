class Solution {
public:
    bool xorGame(vector<int>& nums) {
        int x = 0;
        int n = nums.size();
        for (auto& num : nums) x ^= num;
        if (x == 0) return true;
        return !(n & 1);
    }
};