class Solution {
public:
    bool canPermutePalindrome(string s) {
        vector<int> count(26, 0);
        for (auto& c : s) count[c - 'a']++;
        
        int countOne = 0;
        for (int i = 0; i < 26; ++i) {
            if (count[i] & 1) countOne++;
        }
        
        return countOne <= 1;
    }
};