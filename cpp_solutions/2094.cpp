class Solution {
public:
    vector<int> findEvenNumbers(vector<int>& digits) {
        unordered_set<int> st;
        int n = digits.size();
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < n; ++j) {
                for (int k = 0; k < n; ++k) {
                    if (i == j || j == k || i == k) continue;
                    if (digits[k] & 1) continue;
                    if (digits[i] == 0) continue;
                    int num = digits[i] * 100 + digits[j] * 10 + digits[k];
                    st.insert(num);
                }
            }
        }
        vector<int> res(st.begin(), st.end());
        sort(res.begin(), res.end());
        return res;
    }
};
