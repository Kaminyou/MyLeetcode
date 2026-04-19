class Solution {
public:
    int maxDistance(vector<int>& nums1, vector<int>& nums2) {
        int idx2 = -1;
        int m = nums1.size();
        int n = nums2.size();
        int res = 0;
        for (int idx1 = 0; idx1 < m; ++idx1) {
            while (idx2 < n - 1 && nums2[idx2 + 1] >= nums1[idx1]) idx2++;
            if (idx2 >= idx1) res = max(res, idx2 - idx1);
        }
        return res;
    }
};
