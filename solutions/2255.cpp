class Solution {
public:
    int countPrefixes(vector<string>& words, string s) {
        int count = 0;
        for (auto word : words) {
            if (word.size() > s.size()) continue;
            int lenMin = min(word.size(), s.size());
            
            bool flag = true;
            for (int i = 0; i < lenMin; i++) {
                if (word[i] != s[i]) flag = false;
            }
            count += flag;
        }
        return count;
    }
};