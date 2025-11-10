class Solution {
public:
    int minOperations(vector<int>& nums) {
        stack<int> st;
        st.push(0);
        int res = 0;
        for (auto& num : nums) {
            while (st.top() > num) {
                st.pop();
            }
            if (st.top() < num) {
                res++;
                st.push(num);
            }
        }
        return res;
    }
};

