class Solution {
public:
    int isPrefixOfWord(string sentence, string searchWord) {
        stringstream ss(sentence);
        string token;
        int idx = 0;
        while (getline(ss, token, ' ')) {
            int index = token.find(searchWord);
            if (index != string::npos) {
                if (index == 0) return idx + 1;
            }
            idx++;
        }
        return -1;
    }
};
