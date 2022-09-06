class Solution {
public:
    int numSubarrayBoundedMax(vector<int>& nums, int left, int right) {
        stack<int> st;
        st.push(-1);
        
        int n = nums.size();
        int res = 0;
        for (int i = 0; i < n; ++i) {
            while (st.size() > 1 && nums[i] > nums[st.top()]) {
                int top = st.top();
                st.pop();
                if (nums[top] >= left && nums[top] <= right) {
                    res += (i - top ) * (top - st.top());
                }
            }
            if (nums[i] <= right) st.push(i);
            else {
                while (!st.empty()) st.pop();
                st.push(i);
            }
        }
        while (st.size() > 1) {
            int top = st.top();
            st.pop();
            if (nums[top] >= left && nums[top] <= right) {
                res += (n - top) * (top - st.top());
            }
        }
        return res;
    }
};