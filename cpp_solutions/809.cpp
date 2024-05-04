class Solution {
public:
    vector<pair<char, int>> encode(const string& s) {
        vector<pair<char, int>> res;
        int index = 0;
        int n = s.size();
        while (index < n) {
            int c = s[index];
            int start = index;
            while (index + 1 < n && s[index + 1] == c) index++;
            res.push_back(make_pair(c, index - start + 1));
            index++;
        }
        return res;
    }
    bool check(vector<pair<char, int>>& key, vector<pair<char, int>>& query) {
        if (key.size() != query.size()) return false;
        int n = key.size();
        for (int i = 0; i < n; ++i) {
            if (key[i].first != query[i].first) return false;
            if (key[i].second < query[i].second) return false;
            if (key[i].second > query[i].second && key[i].second < 3) return false;
        }
        return true;
    }
    int expressiveWords(string s, vector<string>& words) {
        vector<pair<char, int>> key = encode(s);
        vector<pair<char, int>> query;
        int res = 0;
        for (auto& word : words) {
            query = encode(word);
            if (check(key, query)) res++;
        }
        return res;
    }
};