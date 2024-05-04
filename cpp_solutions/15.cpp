class Solution {
public:
    vector<vector<int>> res;
    void twoSum(vector<int>& nums, int curr) {
        int a = nums[curr];
        int target = -a;
        int left = curr + 1;
        int right = nums.size() - 1;
        while (right > left) {
            if (nums[left] + nums[right] < target) {
                left++;
            }
            else if (nums[left] + nums[right] > target) {
                right--;
            }
            else {
                res.push_back({a, nums[left], nums[right]});
                while (left + 1 < nums.size() && nums[left + 1] == nums[left]) left++;
                while (right > 0 && nums[right - 1] == nums[right]) right--;
                left++;
                right--;
            }
        }
    }
    vector<vector<int>> threeSum(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            if (i > 0 && nums[i] == nums[i - 1]) continue;
            twoSum(nums, i);
        }
        return res;
    }
};