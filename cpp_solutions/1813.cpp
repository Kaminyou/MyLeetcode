class Solution {
public:
    vector<string> toWords(string& s) {
        stringstream ss(s);
        string token;
        vector<string> v;
        while (getline(ss, token, ' ')) {
            v.push_back(token);
        }
        return v;

    }
    bool areSentencesSimilar(string sentence1, string sentence2) {
        vector<string> s1 = toWords(sentence1);
        vector<string> s2 = toWords(sentence2);
        int i1 = 0;
        int i2 = 0;
        int n1 = s1.size();
        int n2 = s2.size();
        while (i1 < n1 && i1 < n2 && s1[i1] == s2[i1]) i1++;
        while (i1 + i2 < n1 && i1 + i2 < n2 && s1[n1 - 1 - i2] == s2[n2 - 1 - i2]) i2++;
        return (i1 + i2 == n1) || (i1 + i2 == n2);
    }
};

