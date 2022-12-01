class Solution {
public:
    int calculateTime(string keyboard, string word) {
        vector<int> char2idx(26, -1);
        for (int i = 0; i < 26; ++i) char2idx[keyboard[i] - 'a'] = i;
        int current = 0;
        int sum = 0;
        for (auto& c : word) {
            sum += abs(char2idx[c - 'a'] - current);
            current = char2idx[c - 'a'];
        }
        return sum;
    }
};