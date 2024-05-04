class Solution {
public:
    string decodeMessage(string key, string message) {
        vector<int> mapping(26, -1);
        int curr = 0;
        for (auto c : key) {
            if (c == ' ') continue;
            if (mapping[c - 'a'] != -1) continue;
            mapping[c - 'a'] = curr;
            curr++;
        }
        string res;
        for (auto c : message) {
            if (c == ' ') res.push_back(' ');
            else {
                res.push_back(mapping[c - 'a'] + 'a');
            }
        }
        return res;
    }
};