class Solution {
public:
    int findNumberOfLIS(vector<int>& nums) {
        int n = nums.size();
        vector<int> lenDP(n, 1);
        vector<int> countDP(n, 1);
        int maxLen = 1;
        int counting = 0;
        
        for (int i = 0; i < n; i++) {
            for (int j = 0; j < i; j++) {
                if (nums[i] <= nums[j]) continue;
                if (lenDP[j] + 1 == lenDP[i]) countDP[i] += countDP[j];
                else if (lenDP[j] + 1 > lenDP[i]) {
                    lenDP[i] = lenDP[j] + 1;
                    countDP[i] = countDP[j];
                }
            }
            if (lenDP[i] == maxLen) counting += countDP[i];
            else if (lenDP[i] > maxLen) {
                maxLen = lenDP[i];
                counting = countDP[i];
            }
        }
        return counting;
    }
};