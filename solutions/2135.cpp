class Solution {
public:
    int wordCount(vector<string>& startWords, vector<string>& targetWords) {
        unordered_set<int> st;
        
        for (auto& word : startWords) {
            int mask = 0;
            for (auto c : word) {
                mask |= (1 << (c - 'a'));
            }
            st.insert(mask);
        }
        
        int count = 0;
        for (auto& word : targetWords) {
            int mask = 0;
            for (auto c : word) {
                mask |= (1 << (c - 'a'));
            }
            for (int i = 0; i < 26; ++i) {
                if (mask & (1 << i)) {
                    if (st.find(mask ^ (1 << i)) != st.end()) {
                        count++;
                        break;
                    }
                }
            }
        }
        return count;
    }
};