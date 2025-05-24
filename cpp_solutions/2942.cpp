class Solution {
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        vector<int> res;
        int n = words.size();
        for (int i = 0; i < n; ++i) {
            for (auto& c : words[i]) {
                if (c == x) {
                    res.push_back(i);
                    break;
                }
            }
        }
        return res;
    }
};
