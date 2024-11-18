class Solution {
public:
    vector<int> decrypt(vector<int>& code, int k) {
        int n = code.size();
        vector<int> res(n, 0);
        int curr = 0;
        if (k == 0) return res;
        if (k > 0) {
            for (int i = 1; i <= k; ++i) curr += code[(i + 2 * n) % n];
            for (int i = 0; i < n; ++i) {
                res[i] = curr;
                curr -= code[(i + 1) % n];
                curr += code[(i + k + 1) % n];
            }
        }
        else {
            for (int i = -1; i >= k; --i) curr += code[(i + 2 * n) % n];
            for (int i = 0; i < n; ++i) {
                res[i] = curr;
                curr -= code[(i + k + 2 * n) % n];
                curr += code[(i + 2 * n) % n];
            }
        }
        return res;
    }
};
