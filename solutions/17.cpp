class Solution {
public:
    vector<string> res;
    void backtracking(unordered_map<char, string>& mp, string& digits, int currIdx, string& currPath) {
        if (currPath.size() == digits.size()) res.push_back(currPath);
        else {
            for (char c : mp[digits[currIdx]]) {
                currPath.push_back(c);
                backtracking(mp, digits, currIdx + 1, currPath);
                currPath.pop_back();
            }
        }
    }
    vector<string> letterCombinations(string digits) {
        if (digits.size() == 0) return {};
        unordered_map<char, string> mp;
        mp['2'] = "abc";
        mp['3'] = "def";
        mp['4'] = "ghi";
        mp['5'] = "jkl";
        mp['6'] = "mno";
        mp['7'] = "pqrs";
        mp['8'] = "tuv";
        mp['9'] = "wxyz";
        string path = "";
        backtracking(mp, digits, 0, path);
        return res;
    }
};