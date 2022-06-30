class Solution {
public:
    int minMoves2(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int mid = (nums.size() - 1) / 2;
        int target = nums[mid];
        int res = 0;
        for (auto& num : nums) res += abs(num - target);
        return res;
    }
};
// 12345  1234
//   ^     ^
// odd => (size - 1) / 2
// even => (size - 1) / 2