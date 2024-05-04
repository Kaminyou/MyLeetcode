class Solution {
public:
    int maxScore(vector<int>& nums) {
        sort(nums.begin(), nums.end(), greater<int>());
        int n = nums.size();
        long long sum = 0;
        int count = 0;
        for (int i = 0; i < n; ++i) {
            sum += nums[i];
            if (sum > 0) count++;
        }
        return count;
    }
};