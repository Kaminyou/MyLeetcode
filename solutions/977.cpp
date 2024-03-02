class Solution {
public:
    vector<int> sortedSquares(vector<int>& nums) {
        int n = nums.size();
        vector<int> results(n);
        int left = 0;
        int right = n - 1;
        int curr = n - 1;
        while (left <= right) {
            int square;
            if (abs(nums[left]) > abs(nums[right])) {
                square = nums[left];
                left++;
            }
            else {
                square = nums[right];
                right--;
            }
            results[curr] = square * square;
            curr--;
        }
        return results;
    }
};
