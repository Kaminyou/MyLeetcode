class Solution {
public:
    int xorAllNums(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int res = 0;
        if (m & 1) {
            for (int i = 0; i < n; ++i) res ^= nums2[i];
        }
        if (n & 1) {
            for (int i = 0; i < m; ++i) res ^= nums1[i];
        }
        return res;
    }
};