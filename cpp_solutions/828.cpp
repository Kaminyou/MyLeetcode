class Solution {
public:
    int uniqueLetterString(string s) {
        int n = s.size();
        int res = 0;
        vector<int> left(26, -1);
        vector<int> right(26, -1);
        
        for (int i = 0; i < n; i++) {
            int index = s[i] - 'A';
            res += (i - right[index]) * (right[index] - left[index]);
            left[index] = right[index];
            right[index] = i;
        }
        for (int i = 0; i < 26; i++) {
            res += (n - right[i]) * (right[i] - left[i]);
        }
        return res;
    }
};