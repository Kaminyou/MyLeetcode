class Solution {
public:
    string toUpper(string &s) {
        string ss;
        for (auto& c : s) {
            if (c >= 'a') {
                ss.push_back(c - 'a' + 'A');
            }
            else ss.push_back(c);
        }
        return ss;
    }
    bool isVowel(char c) {
        return (c == 'A' || c == 'E' || c == 'I' || c == 'O' || c == 'U');
    }
    string syncVowel(string& s) {
        string ss;
        for (auto& c : s) {
            if (isVowel(c)) ss.push_back('A');
            else ss.push_back(c);
        }
        return ss;
    }
    vector<string> spellchecker(vector<string>& wordlist, vector<string>& queries) {
        unordered_map<string, string> mp1;
        unordered_map<string, string> mp2;
        unordered_map<string, string> mp3;

        for (auto& word : wordlist) {
            mp1[word] = word;
            string upper = toUpper(word);
            if (!mp2.count(upper)) mp2[upper] = word;
            string vowelSynced = syncVowel(upper);
            if (!mp3.count(vowelSynced)) mp3[vowelSynced] = word;
        }
        vector<string> res;
        for (auto& query : queries) {
            if (mp1.count(query)) res.push_back(mp1[query]);
            else {
                string upper = toUpper(query);
                if (mp2.count(upper)) res.push_back(mp2[upper]);
                else {
                    string vowelSynced = syncVowel(upper);
                    if (mp3.count(vowelSynced)) res.push_back(mp3[vowelSynced]);
                    else {
                        res.push_back("");
                    }
                }
            }
        }
        return res;
    }
};

