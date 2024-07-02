class Solution {
public:
    vector<int> intersect(vector<int>& nums1, vector<int>& nums2) {
        vector<int> res;
        vector<int> cnt(1001, 0);
        for (auto& num : nums1) {
            cnt[num] += 1;
        }

        for (auto& num : nums2) {
            if (cnt[num] > 0) {
                res.push_back(num);
                cnt[num] -= 1;
            }
        }
        return res;
    }
};
