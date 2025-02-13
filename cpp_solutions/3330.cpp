class Solution {
public:
    int possibleStringCount(string word) {
        int res = 1;
        int index = 0;
        int n = word.size();
        while (index < n) {
            char c = word[index];
            int start = index;
            while (index + 1 < n && word[index + 1] == c) index++;
            int length = index - start + 1;
            res += (length - 1);
            index++;
        }
        return res;
    }
};
