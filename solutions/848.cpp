class Solution {
public:
    string shiftingLetters(string s, vector<int>& shifts) {
        int n = shifts.size();
        for (int i = n - 2; i >= 0; --i) {
            shifts[i] += (shifts[i + 1] % 26);
            shifts[i] %= 26;
        }
        for (int i = 0; i < n; ++i) {
            int current = s[i] - 'a';
            current += shifts[i];
            current %= 26;
            s[i] = current + 'a';
        }
        return s;
    }
};