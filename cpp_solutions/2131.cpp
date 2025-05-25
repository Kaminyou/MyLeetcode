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

class Solution {
public:
    int longestPalindrome(vector<string>& words) {
        vector<int> hash(26 * 26, 0);
        for (auto& word : words) {
            int key = (word[0] - 'a') * 26 + (word[1] - 'a');
            hash[key]++;
        }
        bool flag = false;
        int cnt = 0;
        for (int i = 0; i < 26; ++i) {
            for (int j = 0; j <= i; ++j) {
                if (i == j) {
                    if (hash[i * 26 + j]) {
                        if (hash[i * 26 + j] & 1) {
                            flag = true;
                        }
                        cnt += hash[i * 26 + j] / 2;
                    }
                }
                else {
                    cnt += min(hash[i * 26 + j], hash[j * 26 + i]);
                }
            }
        }
        return cnt * 4 + flag * 2;
    }
};


