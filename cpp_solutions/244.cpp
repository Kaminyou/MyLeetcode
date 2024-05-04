class WordDistance {
public:
    unordered_map<string, vector<int>> mp;
    WordDistance(vector<string>& wordsDict) {
        for (int i = 0; i < wordsDict.size(); ++i) {
            mp[wordsDict[i]].push_back(i);
        }
    }
    
    int shortest(string word1, string word2) {
        const vector<int>& v1 = mp[word1];
        const vector<int>& v2 = mp[word2];
        int res = INT_MAX;
        int idx1 = 0;
        int idx2 = 0;
        while (idx1 < v1.size() && idx2 < v2.size()) {
            res = min(res, abs(v1[idx1] - v2[idx2]));
            if (v1[idx1] > v2[idx2]) idx2++;
            else if (v1[idx1] < v2[idx2]) idx1++;
            else break;
        }
        return res;
    }
};

/**
 * Your WordDistance object will be instantiated and called as such:
 * WordDistance* obj = new WordDistance(wordsDict);
 * int param_1 = obj->shortest(word1,word2);
 */