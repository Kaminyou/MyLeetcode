class Solution {
public:
    int longestConsecutive(vector<int>& nums) {
        unordered_set<int> st;
        int res = 0;
        for (auto& num : nums) st.insert(num);
        for (auto& num : nums) {
            if (st.count(num - 1) == 0) {
                int start = num;
                int count = 1;
                while (st.count(start + 1)) {
                    start++;
                    count++;
                }
                res = max(res, count);
            }
        }
        return res;
    }
};