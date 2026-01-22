class Solution {
public:
    bool isSorted(vector<int>& nums) {
        int minVal = INT_MIN;
        for (auto& num : nums) {
            if (num < minVal) return false;
            minVal = num;
        }
        return true;
    }
    int minimumPairRemoval(vector<int>& nums) {
        int count = 0;
        while (!isSorted(nums)) {
            count++;
            vector<int> temp;
            int index = 0;
            int currSum = INT_MAX;
            int n = nums.size();
            for (int i = 0; i < n - 1; ++i) {
                int sum = nums[i] + nums[i + 1];
                if (sum < currSum) {
                    currSum = sum;
                    index = i;
                }
            }
            for (int i = 0; i < n; ++i) {
                if (i == index) {
                    temp.push_back(nums[i] + nums[i + 1]);
                    i++;
                }
                else {
                    temp.push_back(nums[i]);
                }
            }
            nums = temp;
        }
        return count;
    }
};
