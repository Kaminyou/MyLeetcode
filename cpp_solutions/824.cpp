class Solution {
public:
    bool isVowel(char c) {
        if (c == 'a' || c == 'A' || c == 'e' || c == 'E' || c == 'i' || c == 'I' || c == 'o' || c == 'O' || c == 'u' || c == 'U') return true;
        return false;
    }
    string toGoatLatin(string sentence) {
        string res;
        int index = 0;
        string token;
        stringstream ss(sentence);
        while (getline(ss, token, ' ')) {
            if (isVowel(token[0])) {
                res += (token + "ma" + string(index + 1, 'a'));
            }
            else {
                res += (token.substr(1) + token[0] + "ma" + string(index + 1, 'a'));
            }
            res.push_back(' ');
            index++;
        }
        res.pop_back();
        return res;
    }
};