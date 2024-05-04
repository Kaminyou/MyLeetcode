class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        unordered_map<string, int> mp;
        bool sameFlag = false;
        for (auto word : words) {
            mp[word]++;
        }
        int res = 0;
        unordered_set<string> st;
        bool flag = false;
        for (auto word : words) {
            if (st.find(word) != st.end()) continue;
            string wordReversed = word;
            reverse(wordReversed.begin(), wordReversed.end());
            int count = min(mp[word], mp[wordReversed]);
            if (word == wordReversed) {
                if (count & 1) flag = true;
                res += (count / 2) * 4;
            }
            else res += count * 4;
            st.insert(word);
            st.insert(wordReversed);
        }

        return res + flag * 2;
    }
};