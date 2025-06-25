class Solution {
public:
    long long kthSmallestProduct(vector<int>& nums1, vector<int>& nums2, long long k) {
        long long left = -1e10;
        long long right = 1e10;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (valid(nums1, nums2, k, mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
    bool valid(vector<int>& nums1, vector<int>& nums2, long long k, long long mid) {
        long long cnt = 0;
        for (int num : nums1) {
            if (num > 0) {
                long long target = floor(mid * 1.0 / num);
                cnt += (upper_bound(nums2.begin(), nums2.end(), target) - nums2.begin());
            }
            else if (num == 0) {
                if (mid >= 0) cnt += nums2.size();
            }
            else {
                long long target = ceil(mid * 1.0 / num);
                auto it = lower_bound(nums2.begin(), nums2.end(), target);
                cnt += nums2.size() - (it - nums2.begin());
            }
        }
        return cnt >= k;
    }
};
