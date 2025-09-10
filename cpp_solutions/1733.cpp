class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        int res = INT_MAX;
        int m = languages.size();
        int k = friendships.size();
        unordered_set<int> needs;
        vector<unordered_set<int>> languageSts(m);
        vector<bool> learns(m, false);
        for (int i = 0; i < m; ++i) {
            for (auto& language : languages[i]) {
                languageSts[i].insert(language);
            }
        }
        for (int j = 0; j < k; ++j) {
            auto friendship = friendships[j];
            int u = friendship[0] - 1;
            int v = friendship[1] - 1;
            bool flag = false;
            for (auto& language : languages[u]) {
                if (languageSts[v].count(language)) {
                    flag = true;
                    break;
                }
            }
            if (flag) continue;
            needs.insert(u);
            needs.insert(v);
        }
        for (int learnLanguage = 1; learnLanguage <= n; ++learnLanguage) {
            int count = 0;
            for (auto& need : needs) {
                if (!languageSts[need].count(learnLanguage)) count++;
            }
            res = min(res, count);
        }
        return res;
    }
};
