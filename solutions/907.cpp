class Solution {
public:
    int sumSubarrayMins(vector<int>& arr) {
        long long ans = 0;
        long long mod = 1e9 + 7;
        stack<int> st;
        int n = arr.size();
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && arr[i] <= arr[st.top()]) {
                int j = st.top();
                st.pop();
                long long left = -1;
                long long right = i;
                if (!st.empty()) left = st.top();
                ans += (right - j) * (j - left) * arr[j];
                ans %= mod;
            }
            st.push(i);
        }
        while (!st.empty()) {
            int j = st.top();
            st.pop();
            long long left = -1;
            long long right = n;
            if (!st.empty()) left = st.top();
            ans += (right - j) * (j - left) * arr[j];
            ans %= mod;
        }
        return ans;
    }
};