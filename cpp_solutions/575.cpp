class Solution {
public:
    int distributeCandies(vector<int>& candyType) {
        int n = candyType.size();
        unordered_set<int> st;
        for (auto& candy : candyType) st.insert(candy);
        int m = st.size();
        return min(n / 2, m);
    }
};