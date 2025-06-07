class Solution {
public:
    string clearStars(string s) {
        vector<vector<int>> hash(26);
        int n = s.size();
        for (int i = 0; i < n; ++i) {
            if (s[i] == '*') {
                s[i] = 'N';
                for (int j = 0; j < 26; ++j) {
                    if (hash[j].size() > 0) {
                        int idx = hash[j].back();
                        s[idx] = 'N';
                        hash[j].pop_back();
                        break;
                    }
                }
            }
            else {
                hash[s[i] - 'a'].push_back(i);
            }
        }
        string res = "";
        for (auto& c : s) {
            if (c != 'N') res.push_back(c);
        }
        return res;
    }
};

