class Solution {
public:
    vector<int> getSneakyNumbers(vector<int>& nums) {
        unordered_set<int> st;
        vector<int> res;
        for (auto& num : nums) {
            if (st.count(num)) res.push_back(num);
            else st.insert(num);
        }
        return res;
    }
};
