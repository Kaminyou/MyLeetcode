class Solution {
public:
    int count(vector<int>& nums, int x) {
        // count of element >= x
        auto it = lower_bound(nums.begin(), nums.end(), x);
        int index = it - nums.begin();
        return nums.size() - index;
    }
    int specialArray(vector<int>& nums) {
        sort(nums.begin(), nums.end());
        int left = 0;
        int right = nums.back() + 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (count(nums, mid) <= mid) right = mid;
            else left = mid + 1;
        }
        
        if (count(nums, left) != left) return -1;
        return left;
    }
};
