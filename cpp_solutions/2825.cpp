class Solution {
public:
    bool canMakeSubsequence(string str1, string str2) {
        if (str2.size() > str1.size()) return false;
        int index2 = 0;
        for (int index1 = 0; index1 < str1.size(); index1++) {
            if (index2 < str2.size()) {
                int c1 = str1[index1] - 'a';
                int c2 = str2[index2] - 'a';
                if (c1 == c2 || (c1 + 1) == c2 || (c1 - 25) == c2) index2++;
            }
        }
        return index2 == str2.size();
    }
};

