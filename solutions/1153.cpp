class Solution {
public:
    bool canConvert(string str1, string str2) {
        vector<int> mapping(26, -1);
        vector<bool> unique(26, false);
        bool allTheSame = true;
        int n = str1.size();
        for (int i = 0; i < n; i++) {
            if (str1[i] != str2[i]) allTheSame = false;
            unique[str2[i] - 'a'] = true;
            if (mapping[str1[i] - 'a'] == -1) {
                mapping[str1[i] - 'a'] = str2[i] - 'a';
            }
            else {
                if (mapping[str1[i] - 'a'] != str2[i] - 'a') return false;
            }
        }
        int count = 0;
        for (int i = 0; i < 26; i++) {
            if (unique[i]) count++;
        }
        if (count == 26 && !allTheSame) return false;
        return true;
    }
};