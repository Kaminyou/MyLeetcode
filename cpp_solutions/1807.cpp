class Solution {
public:
    string evaluate(string s, vector<vector<string>>& knowledge) {
        unordered_map<string, string> mp;
        for (auto& instance : knowledge) {
            mp[instance[0]] = instance[1];
        }
        string res = "";
        int n = s.size();
        int index = 0;
        while (index < n) {
            if (s[index] != '(') {
                res.push_back(s[index]);
                index++;
            }
            else {
                index++;
                string key = "";
                while (s[index] != ')') {
                    key.push_back(s[index]);
                    index++;
                }
                index++;
                if (mp.count(key)) {
                    res += mp[key];
                }
                else {
                    res.push_back('?');
                }
            }
        }
        return res;
    }
};
