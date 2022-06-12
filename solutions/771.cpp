class Solution {
public:
    int numJewelsInStones(string jewels, string stones) {
        unordered_set<char> st;
        for (auto& c : jewels) st.insert(c);
        int res = 0;
        for (auto& c : stones) {
            if (st.find(c) != st.end()) res++;
        }
        return res;
    }
};