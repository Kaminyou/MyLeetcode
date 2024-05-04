class Solution {
public:
    vector<int> mostCompetitive(vector<int>& nums, int k) {
        int n = nums.size();
        int drop = n - k;
        vector<int> st;
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && drop && st.back() > nums[i]) {
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
};