class Solution {
public:
    vector<int> getCount(string& s) {
        vector<int> cnt(26, 0);
        for (auto& c : s) {
            cnt[c - 'a']++;
        }
        vector<int> validNum;
        for (auto& num : cnt) {
            if (num > 0) validNum.push_back(num);
        }
        sort(validNum.begin(), validNum.end());
        int index = 0;
        for (int i = 0; i < 26; ++i) {
            if (cnt[i] != 0) {
                cnt[i] = validNum[index];
                index++;
            }
        }
        return cnt;
    }
    bool closeStrings(string word1, string word2) {
        vector<int> word1Cnt = getCount(word1);
        vector<int> word2Cnt = getCount(word2);
        for (int i = 0; i < 26; ++i) {
            if (word1Cnt[i] != word2Cnt[i]) return false;
        }
        return true;
    }
};