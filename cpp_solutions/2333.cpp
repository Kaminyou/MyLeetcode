class Solution {
public:
    bool criteria(vector<long long>& diff, long long tobe, long long maxCount) {
        long long count = 0;
        for (auto& num : diff) {
            if (num > tobe) count += (num - tobe);
        }
        return count <= maxCount;
    }
    long long remainConut(vector<long long>& diff, long long tobe, long long maxCount) {
        long long count = 0;
        for (auto& num : diff) {
            if (num > tobe) count += (num - tobe);
        }
        return maxCount - count;
    }
    long long minSumSquareDiff(vector<int>& nums1, vector<int>& nums2, int k1, int k2) {
        int n = nums1.size();
        vector<long long> diff(n, 0);
        for (int i = 0; i < n; ++i) {
            diff[i] = abs(nums1[i] - nums2[i]);
        }
        sort(diff.begin(), diff.end());
        long long left = 0;
        long long right = diff[diff.size() - 1];
        long long K = k1 + k2;
        while (left < right) {
            long long mid = left + (right - left) / 2;
            if (criteria(diff, mid, K)) right = mid;
            else left = mid + 1;
        }
        long long remainK = remainConut(diff, left, K);
        if (left == 0) return 0;
        long long res = 0;
        for (auto& num : diff) {
            if (num >= left) {
                if (remainK) {
                    res += (left - 1) * (left - 1);
                    remainK--;
                }
                else {
                    res += left * left;
                }                
            }
            else res += num * num;
        }
        return res;
    }
};