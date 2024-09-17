class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp1;
        unordered_map<string, int> mp2;
        stringstream ss1(s1);
        stringstream ss2(s2);
        string token;
        while (getline(ss1, token, ' ')) {
            mp1[token]++;
        }
        while (getline(ss2, token, ' ')) {
            mp2[token]++;
        }
        vector<string> res;
        for (auto& [s, num] : mp1) {
            if (num == 1 && mp2.count(s) == 0) res.push_back(s);
        }
        for (auto& [s, num] : mp2) {
            if (num == 1 && mp1.count(s) == 0) res.push_back(s);
        }
        return res;
    }
};
