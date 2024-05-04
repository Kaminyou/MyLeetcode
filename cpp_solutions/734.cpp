class Solution {
public:
    bool areSentencesSimilar(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        unordered_map<string, set<string>> mapping;
        for (auto& pair : similarPairs) {
            mapping[pair[0]].insert(pair[1]);
            mapping[pair[1]].insert(pair[0]);
        }
        if (sentence1.size() != sentence2.size()) return false;
        int n = sentence1.size();
        for (int i = 0; i < n; ++i) {
            if (sentence1[i] != sentence2[i]) {
                if (mapping.find(sentence1[i]) == mapping.end() && mapping.find(sentence2[i]) == mapping.end()) return false;
                if (mapping[sentence1[i]].find(sentence2[i]) != mapping[sentence1[i]].end()) continue;
                if (mapping[sentence2[i]].find(sentence1[i]) != mapping[sentence2[i]].end()) continue;
                return false;
            }
        }
        return true;
    }
};