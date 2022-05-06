class Solution {
public:
    string removeDuplicates(string s, int k) {
        vector<pair<int, char>> counts;
        for (int i = 0; i < s.size(); i++) {
            if (counts.empty() || s[i] != counts.back().second) counts.push_back(make_pair(1, s[i]));
            else {
                if (++counts[counts.size() - 1].first == k) counts.pop_back();
            }
        }
        string res;
        for (auto element : counts) {
            res += string(element.first, element.second);
        }
        return res;
    }
};