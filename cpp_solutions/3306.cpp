class Solution {
public:
    int char2index(char c) {
        if (c == 'a') return 0;
        if (c == 'e') return 1;
        if (c == 'i') return 2;
        if (c == 'o') return 3;
        if (c == 'u') return 4;
        return -1;
    }
    bool isCountsValid(vector<int>& counts) {
        for (int i = 0; i < 5; ++i) {
            if (counts[i] < 1) return false;
        }
        return true;
    }
    long long countOfSubstrings(string word, int k) {
        vector<int> counts(5, 0);
        int consonants = 0;
        long long res = 0;
        int n = word.size();
        vector<int> prefix(n + 1, 0);
        for (int i = n - 1; i >= 0; --i) {
            int index = char2index(word[i]);
            if (index != -1) {
                prefix[i] = prefix[i + 1] + 1;
            }
        }
        int right = 0;
        // [left, right)
        for (int left = 0; left < n; ++left) {
            while (!isCountsValid(counts) || consonants < k) {
                if (right == n) break;
                int index = char2index(word[right]);
                right++;
                if (index == -1) consonants++;
                else counts[index]++;
            }
            if (isCountsValid(counts) && consonants == k) {
                res += 1 + prefix[right];
            }
            int index = char2index(word[left]);
            if (index == -1) consonants--;
            else counts[index]--;
        }
        return res;
    }
};
