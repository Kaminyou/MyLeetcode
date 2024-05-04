class Solution {
public:
    bool isSimilar(string& s1, string& s2) {
        vector<bool> hashS1(26, false);
        vector<bool> hashS2(26, false);
        for (auto& c : s1) {
            hashS1[c - 'a'] = true;
        }
        for (auto& c : s2) {
            hashS2[c - 'a'] = true;
        }
        
        for (int i = 0; i < 26; ++i) {
            if (hashS1[i] != hashS2[i]) return false;
        }
        return true;
    }
    int similarPairs(vector<string>& words) {
        int n = words.size();
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isSimilar(words[i], words[j])) cnt++;
            }
        }
        return cnt;
    }
};