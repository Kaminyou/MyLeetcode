class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        sort(nums.begin(), nums.end());
        int cnt = 0;
        int curr = INT_MIN;
        for (auto& num : nums) {
            if (num > curr) {
                cnt++;
                curr = num + k;
            }
        }
        return cnt;
    }
};
