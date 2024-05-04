class Solution {
public:
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        int minVal = nums[k];
        
        int res = 0;
        int left = k;
        int right = k;
        while (left >= 0 || right <= n - 1) {
            res = max(res, minVal * (right - left + 1));
            
            if (left == 0 && right == n - 1) break;
            if (left == 0) {
                right++;
                minVal = min(minVal, nums[right]);
            }
            else if (right == n - 1) {
                left--;
                minVal = min(minVal, nums[left]);
            }
            else {
                if (nums[left - 1] < nums[right + 1]) {
                    right++;
                    minVal = min(minVal, nums[right]);
                }
                else {
                    left--;
                    minVal = min(minVal, nums[left]);
                }
            }
        }
        return res;
    }
};