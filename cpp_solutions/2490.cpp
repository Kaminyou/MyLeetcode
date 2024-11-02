class Solution {
public:
    bool isCircularSentence(string sentence) {
        int n = sentence.size();
        char c = sentence[n - 1];
        string token;
        stringstream ss(sentence);
        while (getline(ss, token, ' ')) {
            int m = token.size();
            char target = token[0];
            if (target != c) return false;
            c = token[m - 1];
        }
        return true;
    }
};
