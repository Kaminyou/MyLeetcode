class Solution {
public:
    long long gcdSum(vector<int>& nums) {
        int n = nums.size();
        vector<int> arr(n, 0);
        int currMax = 0;
        for (int i = 0; i < n; ++i) {
            currMax = max(currMax, nums[i]);
            arr[i] = __gcd(currMax, nums[i]);
        }
        sort(arr.begin(), arr.end());
        int left = 0;
        int right = n - 1;
        long long res = 0;
        while (left < right) {
            res += __gcd(arr[left], arr[right]);
            left++;
            right--;
        }
        return res;
    }
};
