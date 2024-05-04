class Solution {
public:
    string makeGood(string s) {
        string ans;
        for (auto& c : s) {
            if (!ans.empty() && abs(c - ans.back()) == 32) {
                ans.pop_back();
            }
            else {
                ans.push_back(c);
            }
        }
        return ans;
    }
};