class Solution {
public:
    int canBeTypedWords(string text, string brokenLetters) {
        bool hash[26];
        for (auto& c : brokenLetters) {
            hash[c - 'a'] = true;
        }
        int res = 0;
        stringstream ss(text);
        string word;
        while (getline(ss, word, ' ')) {
            bool flag = false;
            for (auto& c : word) {
                if (hash[c - 'a']) {
                    flag = true;
                    break;
                }
            }
            if (!flag) res++;
        }
        return res;
    }
};
