class Solution {
public:
    vector<int> intersection(vector<int>& nums1, vector<int>& nums2) {
        unordered_set<int> nums2st(nums2.begin(), nums2.end());
        unordered_set<int> intersection;
        for (auto& num : nums1) {
            if (nums2st.count(num)) intersection.insert(num);
        }
        vector<int> res;
        for (auto& num : intersection) res.push_back(num);
        return res;
    }
};
