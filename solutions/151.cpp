class Solution {
public:
    string reverseWords(string s) {
        vector<int> word;
        string temp;
        stringstream ss(s);
        vector<string> words;
        while (getline(ss, temp, ' ')) {
            if (temp.size() != 0) {
                words.push_back(temp);
            }
        }
        reverse(words.begin(), words.end());
        string res;
        for (auto& word : words) {
            res += word;
            res.push_back(' ');
        }
        res.pop_back();
        return res;
    }
};