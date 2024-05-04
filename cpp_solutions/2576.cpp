class Solution {
public:
    int maxNumOfMarkedIndices(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int right = n / 2;
        int count = 0;
        
        sort(nums.begin(), nums.end());
        while (left < n / 2 && right < n) {
            if (nums[left] * 2 <= nums[right]) {
                left++;
                right++;
                count += 2;
            }
            else {
                right++;
            }
        }
        return count;
    }
};