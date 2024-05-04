class Solution {
public:
    long long largestPerimeter(vector<int>& nums) {
        int n = nums.size();
        if (n < 3) return -1;
        sort(nums.begin(), nums.end());
        long long sum = 0;
        for (auto num : nums) sum += num;
        for (int i = n - 1; i >= 2; --i) {
            sum -= nums[i];
            if (nums[i] < sum) return sum + nums[i];
        }
        return -1;
    }
};
