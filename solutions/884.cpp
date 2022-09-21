class Solution {
public:
    vector<string> uncommonFromSentences(string s1, string s2) {
        unordered_map<string, int> mp1;
        string token;
        stringstream ss(s1);
        while (getline(ss, token, ' ')) {
            mp1[token]++;
        }
        
        unordered_map<string, int> mp2;
        stringstream ss2(s2);
        while (getline(ss2, token, ' ')) {
            if (mp1.find(token) != mp1.end()) mp1[token] = 2;
            else {
                mp2[token]++;
            }
        }
        vector<string> res;
        for (auto& element : mp1) {
            if (element.second != 1) continue;
            res.push_back(element.first);
        }
        for (auto& element : mp2) {
            if (element.second != 1) continue;
            res.push_back(element.first);
        }
        return res;
    }
};