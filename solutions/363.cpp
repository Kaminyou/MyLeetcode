class Solution {
public:
    int maxSumSubmatrix(vector<vector<int>>& matrix, int k) {
        int m = matrix.size();
        int n = matrix[0].size();
        
        int res = INT_MIN;
        for (int i = 0; i < m; ++i) {
            vector<int> sum(n, 0); // prefixSum of matrix[j:j+(n), k]
            for (int j = i; j < m; ++j) {
                for (int t = 0; t < n; ++t) {
                    sum[t] += matrix[j][t];
                }
                
                int currSum = 0;
                set<int> st;
                st.insert(currSum);
                for (int t = 0; t < n; ++t) {
                    currSum += sum[t];
                    // [...:k] - [...:i] <= k
                    // => [...:i] >= [...:k]- k
                    auto it = st.lower_bound(currSum - k);
                    if (it != st.end()) res = max(res, currSum - *it);
                    st.insert(currSum);
                }
            }
        }
        return res;
    }
};