class Solution {
public:
    int maximumsSplicedArray(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        long long nums1Sum = 0;
        long long nums2Sum = 0;
        for (auto& num : nums1) nums1Sum += num;
        for (auto& num : nums2) nums2Sum += num;
        
        long long res = 0;
        res = max(res, nums1Sum);
        res = max(res, nums2Sum);
        // nums1 -> nums2 // move max diff of nums1 - nums2
        vector<long long> diff(n, 0);
        for (int i = 0; i < n; ++i) {
            diff[i] = nums1[i] - nums2[i];
        }
        long long maxDiff = 0;
        long long currDiff = 0;
        for (int i = 0; i < n; ++i) {
            currDiff += diff[i];
            if (currDiff < 0) {
                currDiff = 0;
            }
            maxDiff = max(maxDiff, currDiff);
        }
        if (maxDiff > 0) {
            res = max(res, nums2Sum + maxDiff);
        }
        
        // nums2 -> nums1
        vector<long long> revDiff(n, 0);
        for (int i = 0; i < n; ++i) {
            revDiff[i] = nums2[i] - nums1[i];
        }
        maxDiff = 0;
        currDiff = 0;
        for (int i = 0; i < n; ++i) {
            currDiff += revDiff[i];
            if (currDiff < 0) {
                currDiff = 0;
            }
            maxDiff = max(maxDiff, currDiff);
        }
        if (maxDiff > 0) {
            res = max(res, nums1Sum + maxDiff);
        }
        return (int)res;
    }
};