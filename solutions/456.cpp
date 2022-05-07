class Solution {
public:
    bool find132pattern(vector<int>& nums) {
        int third = INT_MIN;
        stack<int> st;
        for (int i = nums.size() - 1; i >= 0; --i) {
            int num = nums[i];
            if (num < third) return true;
            // third would be the max one < current num
            // e.g., [3,1,2,5] => current num = 3, third will be 2
            while (!st.empty() && num > st.top()) {
                third = st.top();
                st.pop();
            }
            st.push(num);
        }
        return false;
    }
};