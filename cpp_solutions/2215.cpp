class Solution {
public:
    vector<vector<int>> findDifference(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> nums1Hash(nums1.begin(), nums1.end());
        unordered_set<int> nums2Hash(nums2.begin(), nums2.end());
        vector<vector<int>> res(2);
        for (auto& num : nums1Hash) {
            if (!nums2Hash.count(num)) res[0].push_back(num);
        }
        for (auto& num : nums2Hash) {
            if (!nums1Hash.count(num)) res[1].push_back(num);
        }
        return res;
    }
};