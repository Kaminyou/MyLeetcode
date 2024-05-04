class Solution {
public:
    vector<bool> checkArithmeticSubarrays(vector<int>& nums, vector<int>& l, vector<int>& r) {
        int m = nums.size();
        int n = l.size();
        vector<bool> res;
        for (int i = 0; i < n; ++i) {
            int left = l[i];
            int right = r[i];
            vector<int> meta;
            for (int j = left; j <= right; ++j) {
                meta.push_back(nums[j]);
            }
            sort(meta.begin(), meta.end());
            unordered_set<int> st;
            int k = meta.size();
            bool ans = true;
            for (int j = 0; j < k - 1; ++j) {
                int diff = meta[j + 1] - meta[j];
                st.insert(diff);
                if (st.size() > 1) {
                    ans = false;
                    break;
                }
            }
            res.push_back(ans);
        }
        return res;
    }
};
