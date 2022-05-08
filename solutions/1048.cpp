class Solution {
public:
    static bool compare(const string& s1, const string& s2) {
        return s1.size() < s2.size();
    }
    int longestStrChain(vector<string>& words) {
        unordered_map<string, int> mp;
        sort(words.begin(), words.end(), compare);
        
        int res = 1;
        for (auto word : words) {
            mp[word] = 1;
            if (word.size() == 1) continue;
            for (int i = 0; i < word.size(); i++) {
                string temp = word.substr(0, i) + word.substr(i + 1);
                if (mp.find(temp) != mp.end()) {
                    mp[word] = max(mp[word], mp[temp] + 1);
                }
            }
            res = max(res, mp[word]);
        }
        return res;
    }
};