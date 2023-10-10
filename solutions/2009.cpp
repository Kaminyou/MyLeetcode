class Solution {
public:
    int minOperations(vector<int>& nums) {
        int n = nums.size();
        unordered_set<int> st(nums.begin(), nums.end());
        vector<int> values(st.begin(), st.end());
        sort(values.begin(), values.end());

        int res = INT_MAX;
        int right = 0;
        for (int left = 0; left < values.size(); left++) {
            while (right < values.size() && values[right] - values[left] + 1 <= n) {
                res = min(res, n - (right - left + 1));
                right++;
            }
        }
        return res;
    }
};
