class Solution {
public:
    int singleNumber(vector<int>& nums) {
        int one = 0;
        int two = 0;
        for (auto num : nums) {
            one = (one ^ num) & (~two);
            two = (two ^ num) & (~one);
        }
        return one;
    }
};