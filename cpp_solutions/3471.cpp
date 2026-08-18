class Solution {
public:
    int largestInteger(vector<int>& nums, int k) {
        if (k == 1) {
            unordered_map<int, int> counts;
            for (auto& num : nums) {
                counts[num]++;
            }
            int res = -1;
            for (auto& [v, cnt] : counts) {
                if (cnt == 1) res = max(res, v);
            }
            return res;
        }
        else if (k >= 2 && nums.size() == k) {
            return *max_element(nums.begin(), nums.end());
        }
        else {
            int n = nums.size();
            int left = nums[0];
            int right = nums[n - 1];
            if (left == right) return -1;
            if (left > right) swap(left, right);
            // left < right
            for (int i = 1; i < n - 1; ++i) {
                if (nums[i] == left) left = -1;
                if (nums[i] == right) right = -1;
            }
            return max(left, right);
        }
    }
};
// k = 1 => largest one that appear only once
// k >= 2; size = k => largest value
// k >= 2; size >= k + 1 => only left and right
