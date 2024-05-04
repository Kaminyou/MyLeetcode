struct Compare {
    vector<int> mp;
    Compare(vector<int>& mapping) {
        mp = mapping;
    }
    bool operator() (const char c1, const char c2) {
        return mp[c1 - 'a'] < mp[c2 - 'a'];
    }
};
class Solution {
public:
    string customSortString(string order, string s) {
        vector<int> mapping(26, -1);
        for (int i = 0; i < order.size(); ++i) {
            mapping[order[i] - 'a'] = i;
        }
        vector<char> temp;
        for (auto& c : s) {
            if (mapping[c - 'a'] != -1) temp.push_back(c);
        }
        sort(temp.begin(), temp.end(), Compare(mapping));
        int index = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (mapping[s[i] - 'a'] != -1) {
                s[i] = temp[index];
                index++;
            }
        }
        return s;
    }
};