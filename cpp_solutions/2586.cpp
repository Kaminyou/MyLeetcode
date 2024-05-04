class Solution {
public:
    int vowelStrings(vector<string>& words, int left, int right) {
        int n = words.size();
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (i < left || i > right) continue;
            int m = words[i].size();
            if (!(words[i][0] == 'a' || words[i][0] == 'e' || words[i][0] == 'i' || words[i][0] == 'o' || words[i][0] == 'u')) continue;
            if (!(words[i][m - 1] == 'a' || words[i][m - 1] == 'e' || words[i][m - 1] == 'i' || words[i][m - 1] == 'o' || words[i][m - 1] == 'u')) continue;
            count++;
        }
        return count;
    }
};