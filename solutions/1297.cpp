class Solution {
public:
    int countUnique(const string& s, vector<bool>& hash) {
        int count = 0;
        for (auto c : s) {
            if (hash[c - 'a'] == false) count++;
            hash[c - 'a'] = true;
        }
        return count;
    }
    int maxFreq(string s, int maxLetters, int minSize, int maxSize) {
        unordered_map<string, int> mp;
        for (int i = 0; i < s.size(); i++) {
            if (i + minSize <= s.size()) mp[s.substr(i, minSize)]++;
        }
        
        int res = 0;
        vector<bool> hash(26, false);
        for (auto element : mp) {
            if (countUnique(element.first, hash) <= maxLetters) res = max(res, element.second);
            for (int i = 0; i < 26; i++) hash[i] = false;
        }
        return res;
    }
};