class Solution {
public:
    int maximumCount(vector<int>& nums) {
        int pos = 0;
        int neg = 0;
        for (auto& num : nums) {
            if (num < 0) neg++;
            if (num > 0) pos++;
        }
        return max(pos, neg);
    }
};