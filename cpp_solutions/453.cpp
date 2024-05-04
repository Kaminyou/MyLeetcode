class Solution {
public:
    int minMoves(vector<int>& nums) {
        int minVal = *min_element(nums.begin(), nums.end());
        int res = 0;
        for (auto& num : nums) res += (num - minVal);
        return res;
    }
};
