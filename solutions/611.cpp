class Solution {
public:
    int triangleNumber(vector<int>& nums) {
        int n = nums.size();
        sort(nums.begin(), nums.end());
        int res = 0;
        for (int i = 0; i < n - 2; ++i) {
            if (nums[i] == 0) continue;
            int k = i + 2;
            for (int j = i + 1; j < n - 1; ++j) {
                while (k < n && nums[i] + nums[j] > nums[k]) k++;
                res += (k - j - 1);
            }
        }
        return res;
    }
};
