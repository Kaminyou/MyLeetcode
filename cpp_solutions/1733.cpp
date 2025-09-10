class Solution {
public:
    int minimumTeachings(int n, vector<vector<int>>& languages, vector<vector<int>>& friendships) {
        //vector<int> teach(n, 0);
        int res = INT_MAX;
        int m = languages.size();
        int k = friendships.size();
        vector<bool> skips(k, false);
        vector<set<int>> languageSts(m);
        vector<bool> learns(m, false);
        for (int i = 0; i < m; ++i) {
            for (auto& language : languages[i]) {
                languageSts[i].insert(language);
            }
        }
        for (int learnLanguage = 1; learnLanguage <= n; ++learnLanguage) {
            for (int i = 0; i < m; ++i) learns[i] = false;
            for (int j = 0; j < k; ++j) {
                if (skips[j]) continue;
                auto friendship = friendships[j];
                int u = friendship[0] - 1;
                int v = friendship[1] - 1;
                bool flag = false;
                for (auto& language : languages[u]) {
                    if (languageSts[v].count(language)) {
                        flag = true;
                        skips[j] = true;
                        break;
                    }
                }
                if (flag) continue;
                if (!languageSts[u].count(learnLanguage)) learns[u] = true;
                if (!languageSts[v].count(learnLanguage)) learns[v] = true;
            }
            int count = 0;
            for (int i = 0; i < m; ++i) {
                if (learns[i]) count++;
            }
            res = min(res, count);
        }
        return res;
    }
};
