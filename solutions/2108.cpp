class Solution {
public:
    bool isPalindrome(string& word) {
        int n = word.size();
        int half = n / 2;
        for (int i = 0; i < half; ++i) {
            if (word[i] != word[n - 1 - i]) return false;
        }
        return true;
    }
    string firstPalindrome(vector<string>& words) {
        for (auto& word : words) {
            if (isPalindrome(word)) return word;
        }
        return "";
    }
};
