class Solution {
public:
    vector<int> nextGreaterElement(vector<int>& nums1, vector<int>& nums2) {
        unordered_map<int, int> num2nextGreater;
        stack<int> st; // monotinic dreasing
        
        for (int i = 0; i < nums2.size(); ++i) {
            while (!st.empty() && nums2[i] > nums2[st.top()]) {
                int curr = st.top();
                st.pop();
                num2nextGreater[nums2[curr]] = nums2[i]; 
            }
            st.push(i);
        }
        int n = nums1.size();
        vector<int> res(n, -1);
        for (int i = 0; i < n; ++i) {
            if (num2nextGreater.find(nums1[i]) != num2nextGreater.end()) {
                res[i] = num2nextGreater[nums1[i]];
            }
        }
        return res;
    }
};

