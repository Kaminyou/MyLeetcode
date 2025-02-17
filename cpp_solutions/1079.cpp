class Solution {
public:
    unordered_set<string> st;
    void backtracking(string& tiles, int mask, string& current, int index) {
        if (current.size() >= 1) st.insert(current);
        if (index == tiles.size()) {
            return;
        }
        else {
            int n = tiles.size();
            for (int i = 0; i < n; ++i) {
                if (!(mask & (1 << i))) {
                    current.push_back(tiles[i]);
                    mask ^= (1 << i);
                    backtracking(tiles, mask, current, index + 1);
                    mask ^= (1 << i);
                    current.pop_back();
                }
            }
        }
    }
    int numTilePossibilities(string tiles) {
        string current = "";
        int mask = 0;
        backtracking(tiles, mask, current, 0);
        return st.size();

    }
};
