class Solution {
public:
    int numSubseq(vector<int>& nums, int target) {
        sort(nums.begin(), nums.end());
        int n = nums.size();
        int mod = 1e9 + 7;
        int left = 0;
        int right = n - 1;
        int count = 0;
        vector<int> powerOfTwo(n, 0);
        powerOfTwo[0] = 1;
        for (int i = 1; i < n; ++i) {
            int current = powerOfTwo[i - 1] * 2;
            current %= mod;
            powerOfTwo[i] = current;
        }

        while (left <= right) {
            while (right >= 0 && nums[right] + nums[left] > target) right--;
            if (left > right) break;
            count += powerOfTwo[right - left];
            count %= mod;
            left++;
        }
        return count;
    }
};
