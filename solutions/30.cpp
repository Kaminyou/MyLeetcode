class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        vector<int> res;
        int n = words.size();
        int l = words[0].size();
        if (s.size() < n * l) return res;
        unordered_map<string, int> mp;
        for (auto& word : words) mp[word]++;
        
        for (int i = 0; i <= s.size() - n * l; ++i) {
            unordered_map<string, int> counting;
            int j = 0;
            for (; j < n; ++j) {
                string temp = s.substr(i + j * l, l);
                if (mp.find(temp) == mp.end()) break;
                counting[temp]++;
                if (counting[temp] > mp[temp]) break;
            }
            if (j == n) res.push_back(i);
        }
        return res;
    }
};

// V2
class Solution {
public:
    vector<int> findSubstring(string s, vector<string>& words) {
        int n = words.size();
        int index = 0;
        unordered_map<string, int> word2idx;
        unordered_map<string, int> wordCnt;
        for (int i = 0; i < n; ++i) {
            wordCnt[words[i]]++;
            if (word2idx.find(words[i]) == word2idx.end()) {
                word2idx[words[i]] = index;
                index++;
            }
        }
        int uniqueSize = word2idx.size();
        
        vector<int> res;
        int m = words[0].size();
        for (int i = 0; i < m; ++i) {
            vector<int> counts(uniqueSize, 0);
            int unique = 0;
            for (int j = i; j + m <= s.size(); j += m) {
                string current = s.substr(j, m);
                if ((j - n * m) >= 0) {
                    string previous = s.substr(j - n * m, m);
                    if (word2idx.find(previous) != word2idx.end()) {
                        if (counts[word2idx[previous]] == wordCnt[previous]) unique--;
                        counts[word2idx[previous]]--;
                    }
                }
                if (word2idx.find(current) != word2idx.end()) {
                    
                    counts[word2idx[current]]++;
                    if (counts[word2idx[current]] == wordCnt[current]) unique++;
                }
                if (unique == uniqueSize) res.push_back(j - (n - 1) * m);
            }
        }
        return res;
    }
};