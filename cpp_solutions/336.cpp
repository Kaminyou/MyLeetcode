class Solution {
public:
    bool isPalindrome(string& s, int left, int right) {
        while (left < right) {
            if (s[left] != s[right]) return false;
            left++;
            right--;
        }
        return true;
    }
    vector<vector<int>> palindromePairs(vector<string>& words) {
        vector<vector<int>> res;
        unordered_map<string, int> word2idx;
        set<int> sizeSt;
        for (int i = 0; i < words.size(); ++i) {
            word2idx[words[i]] = i;
            sizeSt.insert(words[i].size());
        }
        
        for (int i = 0; i < words.size(); ++i) {
            string t = words[i];
            reverse(t.begin(), t.end());
            if (word2idx.find(t) != word2idx.end() && word2idx[t] != i) {
                res.push_back({i, word2idx[t]});
            }
            int length = t.size();
            auto maxIt = sizeSt.find(length);
            for (auto it = sizeSt.begin(); it != maxIt; ++it) {
                int subLen = *it;
                string subRight = t.substr(length - subLen);
                if (isPalindrome(t, 0, length - subLen - 1) && word2idx.find(subRight) != word2idx.end()) {
                    res.push_back({i, word2idx[subRight]});
                }
                string subLeft = t.substr(0, subLen);
                if (isPalindrome(t, subLen, length - 1) && word2idx.find(subLeft) != word2idx.end()) {
                    res.push_back({word2idx[subLeft], i});
                }
            }
        }
        return res;
    }
};