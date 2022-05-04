class Solution {
public:
    int longestOnes(vector<int>& nums, int k) {
        int zeroCount = 0;
        int left = 0;
        int right = 0;
        
        int res = 0;
        for (; right < nums.size(); right++) {
            if (nums[right] == 0) zeroCount++;
            while (zeroCount > k) {
                if (nums[left] == 0) zeroCount--;
                left++;
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};