class Solution {
public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        vector<int> unionChar(26, 0);
        for (auto& word : words2) {
            vector<int> tempCount(26, 0);
            for (auto c : word) {
                tempCount[c - 'a']++;
            }
            
            for (int i = 0; i < 26; ++i) {
                unionChar[i] = max(unionChar[i], tempCount[i]);
            }
        }
        
        vector<string> res;
        for (auto& word : words1) {
            vector<int> count(26, 0);
            for (auto c : word) count[c - 'a']++;
            
            bool flag = true;
            for (int i = 0; i < 26; ++i) {
                if (unionChar[i] > count[i]) {
                    flag = false;
                    break;
                }
            }
            if (flag) res.push_back(word);
        }
        return res;
    }
};