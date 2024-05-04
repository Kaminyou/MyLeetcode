class Solution {
public:
    int reductionOperations(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int index = 0;
        int n = nums.size();
        int ans = 0;
        while (index < n) {
            int start = index;
            int num = nums[index];
            while (index + 1 < n && nums[index + 1] == num) {
                index++;
            }
            ans += (n - index - 1);
            index++;
        }
        return ans;
    }
};
