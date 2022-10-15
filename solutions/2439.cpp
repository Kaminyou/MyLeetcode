class Solution {
public:
    int minimizeArrayValue(vector<int>& nums) {
        int n = nums.size();
        int minVal = nums[0];
        long long sum = 0;
        for (int i = 0; i < n - 1; ++i) {
            int left = nums[i];
            int right = nums[i + 1];
            sum += left;
 
            long long mean = (sum + right) / (i + 2);
            long long remain = (sum + right) % (i + 2);
            if (remain > 0) mean++;
            minVal = max(minVal, int(mean));
        }
        return minVal;
    }
};
