class Solution {
public:
    bool isLarger(vector<int>& nums1, vector<int>& nums2, int idx1, int idx2) {
        while (idx1 < nums1.size() && idx2 < nums2.size()) {
            if (nums1[idx1] > nums2[idx2]) return true;
            else if (nums1[idx1] < nums2[idx2]) return false;
            idx1++;
            idx2++;
        }
        if (idx1 < nums1.size()) return true;
        return false;
    }
    vector<int> merge(vector<int>& nums1, vector<int>& nums2) {
        int m = nums1.size();
        int n = nums2.size();
        int idx1 = 0;
        int idx2 = 0;
        vector<int> res;
        while (idx1 < m || idx2 < n) {
            if (isLarger(nums1, nums2, idx1, idx2)) {
                res.push_back(nums1[idx1]);
                idx1++;
            }
            else {
                res.push_back(nums2[idx2]);
                idx2++;
            }
        }
        return res;
    }
    vector<int> extractMaxSubSeq(vector<int>& nums, int k) {
        int n = nums.size();
        int drop = n - k;
        vector<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && drop > 0 && st.back() < nums[i]) {
                st.pop_back();
                drop--;
            }
            st.push_back(nums[i]);
        }
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(st[i]);
        }
        return res;
    }
    vector<int> maxNumber(vector<int>& nums1, vector<int>& nums2, int k) {
        vector<int> res(k, 0);
        vector<int> tempRes;
        
        int m = nums1.size();
        int n = nums2.size();
        for (int k1 = 0; k1 <= min(m, k); ++k1) {
            int k2 = k - k1;
            if (k2 > nums2.size()) continue;
            vector<int> nums1Extacted = extractMaxSubSeq(nums1, k1);
            vector<int> nums2Extacted = extractMaxSubSeq(nums2, k2);
            tempRes = merge(nums1Extacted, nums2Extacted);
            if (isLarger(tempRes, res, 0, 0)) {
                res = tempRes;
            }
        }
        return res;
    }
};