class Solution {
public:
    vector<string> twoEditWords(vector<string>& queries, vector<string>& dictionary) {
        vector<string> res;
        for (auto& query : queries) {
            for (auto& word : dictionary) {
                int diff = 0;
                int n = query.size();
                for (int i = 0; i < n; ++i) {
                    if (query[i] != word[i]) diff++;
                }
                if (diff <= 2) {
                    res.push_back(query);
                    break;
                }
            }
        }
        return res;
    }
};