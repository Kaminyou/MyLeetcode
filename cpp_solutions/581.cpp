class Solution {
public:
    int findUnsortedSubarray(vector<int>& nums) {
        stack<int> st;
        int n = nums.size();
        
        int leftBoundary = INT_MAX; // correct position
        for (int i = 0; i < n; i++) {
            while (!st.empty() && nums[i] < nums[st.top()]) {
                leftBoundary = min(leftBoundary, st.top());
                st.pop();
            }
            st.push(i);
        }
        
        while (!st.empty()) st.pop();
        int rightBoundary = INT_MIN; // correct position
        for (int i = n - 1; i >= 0; i--) {
            while (!st.empty() && nums[i] > nums[st.top()]) {
                rightBoundary = max(rightBoundary, st.top());
                st.pop();
            }
            st.push(i);
        }
        
        if (leftBoundary == INT_MAX) return 0;
        return rightBoundary - leftBoundary + 1;
    }
};