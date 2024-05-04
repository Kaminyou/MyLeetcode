class Solution {
public:
    int counting(vector<int>& array) {
        int n = array.size();
        stack<int> st;
        vector<int> sum(n, 0);
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && array[st.top()] >= array[i]) st.pop();
            if (!st.empty()) {
                int prevIdx = st.top();
                sum[i] = sum[prevIdx];
                sum[i] += array[i] * (i - prevIdx);
            }
            else {
                sum[i] = array[i] * (i + 1); // i - (-1)
            }
            st.push(i);
        }
        int res = 0;
        for (auto& num : sum) res += num;
        return res;
    }
    int numSubmat(vector<vector<int>>& mat) {
        int M = mat.size();
        int N = mat[0].size();
        
        int res = 0;
        vector<int> h(N, 0);
        for (int i = 0; i < M; ++i) {
            for (int j = 0; j < N; ++j) {
                if (mat[i][j] == 0) h[j] = 0;
                else h[j]++;
            }
            res += counting(h);
        }
        return res;
    }
};