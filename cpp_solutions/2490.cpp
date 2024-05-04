class Solution {
public:
    bool isCircularSentence(string sentence) {
        vector<string> words;
        string temp;
        stringstream ss(sentence);
        while (getline(ss, temp, ' ')) {
            words.push_back(temp);
        }
        words.push_back(words[0]);
        int n = words.size();
        for (int i = 0; i < n - 1; ++i) {
            if (words[i].back() != words[i + 1].front()) return false;
        }
        return true;
    }
};