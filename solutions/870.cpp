class Solution {
public:
    vector<int> advantageCount(vector<int>& nums1, vector<int>& nums2) {
        int n = nums1.size();
        sort(nums1.begin(), nums1.end());
        vector<pair<int, int>> nums2wIdx;
        for (int i = 0; i < n; ++i) {
            nums2wIdx.push_back({nums2[i], i});
        }
        sort(nums2wIdx.begin(), nums2wIdx.end());
        vector<int> res(n, -1);
        int left = 0;
        int right = n - 1;
        for (int i = n - 1; i >= 0; --i) {
            if (nums1[right] > nums2wIdx[i].first) {
                res[nums2wIdx[i].second] = nums1[right];
                right--;
            }
            else {
                res[nums2wIdx[i].second] = nums1[left];
                left++;
            }
        }
        return res;
    }
};