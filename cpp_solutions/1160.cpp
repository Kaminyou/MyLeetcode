class Solution {
public:
    int countCharacters(vector<string>& words, string chars) {
        vector<int> charHash(26, 0);
        for (auto c : chars) {
            charHash[c - 'a']++;
        }
        
        int res = 0;
        for (auto& word : words) {
            vector<int> wordHash(26, 0);
            for (auto c : word) {
                wordHash[c - 'a']++;
            }
            
            bool flag = true;
            for (int i = 0; i < 26; ++i) {
                if (wordHash[i] > charHash[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) res += word.size();
        }
        return res;
    }
};