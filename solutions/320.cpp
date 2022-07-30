class Solution {
public:
    vector<string> res;
    void backtracking(string& word, int position, int count, string currStr) {
        if (position == word.size()) {
            if (count) currStr += to_string(count);
            res.push_back(currStr);
            return;
        }
        
        backtracking(word, position + 1, count + 1, currStr);
        backtracking(word, position + 1, 0, currStr + (count > 0 ? to_string(count) : "") + word[position]);
    }
    vector<string> generateAbbreviations(string word) {
        backtracking(word, 0, 0, "");
        return res;
    }
};