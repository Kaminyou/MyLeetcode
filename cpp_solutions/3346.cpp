class Solution {
public:
    int maxFrequency(vector<int>& nums, int k, int numOperations) {
        int maxNum = 0;
        int minNum = INT_MAX;
        unordered_map<int, int> mp;
        for (auto& num : nums) {
            mp[num]++;
            maxNum = max(num, maxNum);
            minNum = min(num, minNum);
        }
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int left = 0;
        int right = 0;
        int res = 0;
        for (int num = minNum; num <= maxNum; ++num) {
            while (left < n && nums[left] + k < num) left++;
            while (right < n && nums[right] - k <= num) right++;
            // [left, right)
            int cnt = right - left;
            int curr = mp[num];
            res = max(res, curr + min(cnt - curr, numOperations));
        }
        return res;
    }
};

