class Solution {
public:
    int totalStrength(vector<int>& strength) {
        const int mod = 1e9 + 7;
        int n = strength.size();
        vector<long long> leftPrefixSum(n + 1, 0);
        vector<long long> leftPrefixMulti(n + 1, 0);
        vector<long long> rightPrefixSum(n + 1, 0);
        vector<long long> rightPrefixMulti(n + 1, 0);
        
        for (int i = 0; i < n; ++i) {
            leftPrefixSum[i + 1] = (leftPrefixSum[i] + strength[i]) % mod;
            leftPrefixMulti[i + 1] = (leftPrefixMulti[i] + (long long)(i + 1) * strength[i]) % mod;
        }
        
        for (int i = n - 1; i >= 0; --i) {
            rightPrefixSum[i] = (rightPrefixSum[i + 1] + strength[i]) % mod;
            rightPrefixMulti[i] = (rightPrefixMulti[i + 1] + (long long)(n - i) * strength[i]) % mod;
        }
        
        stack<int> st; // monotonic increasing
        long long res = 0;
        for (int right = 0; right <= n; ++right) {
            while (!st.empty() && (right == n || strength[right] <= strength[st.top()])) {
                int pivot = st.top();
                st.pop();
                long long left = st.empty() ? 0 : st.top() + 1;
                long long leftSum = (mod + leftPrefixMulti[pivot + 1] - leftPrefixMulti[left] - left * (leftPrefixSum[pivot + 1] - leftPrefixSum[left])) % mod;
                long long rightSum = (mod + rightPrefixMulti[pivot + 1] - rightPrefixMulti[right] - (n - right) * (rightPrefixSum[pivot + 1] - rightPrefixSum[right])) % mod;
                
                long long allSum = (mod + leftSum * (right - pivot) + rightSum * (pivot - left + 1)) % mod;
                res = (res + allSum * strength[pivot]) % mod;
            }
            st.push(right);
        }
        return res;
    }
};