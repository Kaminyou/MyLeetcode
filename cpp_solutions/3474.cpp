class Solution {
public:
    bool isEqual(string& s, string& str2, int start, int m) {
        for (int j = 0; j < m; ++j) {
            int pos = start + j;
            if (s[pos] != str2[j]) {
                return false;
            }
        }
        return true;
    }
    string generateString(string str1, string str2) {
        int n = str1.size();
        int m = str2.size();
        int L = n + m - 1;
        string word(L, '0');
        vector<bool> canChange(L, true);

        for (int i = 0; i < n; ++i) {
            if (str1[i] == 'T') {
                for (int j = 0; j < m; ++j) {
                    int pos = i + j;
                    if (word[pos] != '0' && word[pos] != str2[j]) return "";
                    word[pos] = str2[j];
                    canChange[pos] = false;
                }
            }
        }
        for (int i = 0; i < L; ++i) {
            if (word[i] == '0') {
                word[i] = 'a';
            }
        }

        for (int i = 0; i < n; ++i) {
            if (str1[i] == 'F') {
                if (isEqual(word, str2, i, m)) {
                    bool isFix = false;
                    for (int j = m - 1; j >= 0; --j) {
                        int pos = i + j;
                        if (canChange[pos]) {
                            word[pos] = 'b';
                            canChange[pos] = false;
                            isFix = true;
                            break;
                        }
                    }
                    if (!isFix) return "";
                }
            }
        }
        return word;
    }
};

