class Solution {
public:
    string answerString(string word, int numFriends) {
        if (numFriends == 1) return word;
        int n = word.size();
        // max size = word.size() - numFriends + 1
        // 1 ~ size substring
        int size = n - numFriends + 1;
        char maxChr = 'a';
        string res = "";
        for (int i = 0; i < n; ++i) {
            if (word[i] > maxChr) maxChr = word[i];
        }
        for (int i = 0; i < n; ++i) {
            if (word[i] == maxChr) {
                string sub = word.substr(i, min(size, n - i));
                if (sub > res) res = sub;
            }
        }
        
        return res;
    }
};
