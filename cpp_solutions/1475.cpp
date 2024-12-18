class Solution {
public:
    vector<int> finalPrices(vector<int>& prices) {
        int n = prices.size();
        vector<int> res(n, 0);
        stack<int> st;
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && st.top() > prices[i]) st.pop();
            int discount = 0;
            if (!st.empty()) discount = st.top();
            res[i] = prices[i] - discount;
            st.push(prices[i]);
        }
        return res;
    }
};
