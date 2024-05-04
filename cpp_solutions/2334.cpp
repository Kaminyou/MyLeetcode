class Solution {
public:
    int validSubarraySize(vector<int>& nums, int threshold) {
        int n = nums.size();
        vector<int> prevSmaller(n, -1);
        vector<int> nextSmaller(n, -1);
        
        stack<int> st;
        
        // next smaller
        // monotonic increase (has duplicate)
        for (int i = 0; i < n; ++i) {
            while (!st.empty() && nums[i] < nums[st.top()]) {
                nextSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        while (!st.empty()) st.pop();
        // prev smaller
        // monotonic increase (has duplicate)
        for (int i = n - 1; i >= 0; --i) {
            while (!st.empty() && nums[i] < nums[st.top()]) {
                prevSmaller[st.top()] = i;
                st.pop();
            }
            st.push(i);
        }
        
        
        for (int i = 0; i < n; ++i) {
            int left = prevSmaller[i];
            int right = nextSmaller[i] == -1 ? n : nextSmaller[i];
            int length = right - left - 1;
            if ((long long)nums[i] * length > (long long)threshold) return length;
        }
        
        return -1;
    }
};