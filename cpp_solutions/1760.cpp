class Solution {
public:
    bool valid(vector<int>& nums, int maxOperations, int mid) {
        for (int num : nums) {
            int cnt = num / mid + (num % mid != 0);
            cnt--;
            maxOperations -= cnt;
        }
        return maxOperations >= 0;
    }
    int minimumSize(vector<int>& nums, int maxOperations) {
        int left = 1;
        int right = INT_MAX;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (valid(nums, maxOperations, mid)) {
                right = mid;
            }
            else left = mid + 1;
        }
        return left;
    }
};
