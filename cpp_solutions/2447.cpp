class Solution {
public:
    int subarrayGCD(vector<int>& nums, int k) {
        int n = nums.size();
        int res = 0;
        for (int left = 0; left < n; ++left) {
            int gcd = nums[left];
            if (gcd == k) res++;
            for (int right = left + 1; right < n; ++right) {
                gcd = __gcd(gcd, nums[right]);
                if (gcd == k) res++;
                if (gcd < k) break;
            }
        }
        return res;
    }
};

