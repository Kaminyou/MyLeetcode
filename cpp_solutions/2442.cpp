class Solution {
public:
    int countDistinctIntegers(vector<int>& nums) {
        unordered_set<int> st;
        for (auto& num : nums) {
            st.insert(num);
            string temp = to_string(num);
            reverse(temp.begin(), temp.end());
            int rev = stoi(temp);
            st.insert(rev);
        }
        return st.size();
    }
};