class Solution {
public:
    string addSpaces(string s, vector<int>& spaces) {
        string res;
        int index = 0;
        int spaceIdx = 0;
        while (index < s.size()) {
            if (spaceIdx < spaces.size() && index == spaces[spaceIdx]) {
                res.push_back(' ');
                res.push_back(s[index]);
                index++;
                spaceIdx++;
            }
            else {
                res.push_back(s[index]);
                index++;
            }
        }
        return res;
    }
};
