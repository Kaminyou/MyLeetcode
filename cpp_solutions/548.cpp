class Solution {
public:
    bool splitArray(vector<int>& nums) {
        int n = nums.size();
        if (n < 7) return false;
        
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + nums[i];
        }
        for (int j = 3; j <= n - 4; ++j) {
            unordered_set<int> st;
            for (int i = 1; i <= j - 2; ++i) {
                if (prefixSum[i] - prefixSum[0] == prefixSum[j] - prefixSum[i + 1]) {
                    st.insert(prefixSum[i] - prefixSum[0]);
                }
            }
            for (int k = j + 2; k <= n - 2; ++k) {
                if (prefixSum[k] - prefixSum[j + 1] == prefixSum[n] - prefixSum[k + 1]) {
                    if (st.find(prefixSum[k] - prefixSum[j + 1]) != st.end()) return true;
                }
            }
        }
        return false;
    }
};

// a | b | c | d => min length = 7