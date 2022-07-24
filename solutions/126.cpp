class Solution {
public:
    bool differentByOne(string& s1, string& s2) {
        int count = 0;
        int n = s1.size();
        for (int i = 0; i < n; ++i) {
            if (s1[i] != s2[i]) count++;
            if (count > 1) return false;
        }
        return count == 1;
    }

    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        int n = wordList.size();
        int index = 0;
        unordered_map<string, int> word2idx;
        unordered_map<int, string> idx2word;
        word2idx[beginWord] = index;
        idx2word[index] = beginWord;
        index++;
        bool beginInList = false;
        for (auto& word : wordList) {
            if (word2idx.find(word) != word2idx.end()) {
                beginInList = true;
                continue;
            }
            word2idx[word] = index;
            idx2word[index] = word;
            index++;
        }
        
        if (word2idx.find(endWord) == word2idx.end()) return {};

        vector<vector<int>> adjacency(n + 1);
        if (!beginInList) {
            for (int i = 0; i < n; ++i) {
                if (differentByOne(beginWord, wordList[i])) {
                    int wordIIdx = word2idx[wordList[i]];
                    adjacency[wordIIdx].push_back(0);
                    adjacency[0].push_back(wordIIdx);
                }
            }
        }
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (differentByOne(wordList[i], wordList[j])) {
                    int wordIIdx = word2idx[wordList[i]];
                    int wordJIdx = word2idx[wordList[j]];
                    adjacency[wordIIdx].push_back(wordJIdx);
                    adjacency[wordJIdx].push_back(wordIIdx);
                }
            }
        }
        
        int beginIdx = word2idx[beginWord];
        int targetIdx = word2idx[endWord];
        vector<int> visited(n + 1, INT_MAX);
        queue<int> q;
        q.push(beginIdx);
        visited[beginIdx] = 0;

        int length = 0;
        int minStep = INT_MAX;
        while (!q.empty()) {
            int size = q.size();
            for (int i = 0; i < size; ++i) {
                auto node = q.front();
                q.pop();
                if (node == targetIdx) {
                    minStep = min(minStep, length);
                }
                for (auto& neighbor : adjacency[node]) {
                    if (length + 1 < visited[neighbor]) {
                        visited[neighbor] = length + 1;
                        q.push(neighbor);
                    }
                }
            }
            length++;
        }
        
        if (minStep == INT_MAX) return {};
        
        
        queue<vector<int>> seqQ;
        seqQ.push({targetIdx});
        length = minStep;
        while (length) {
            int size = seqQ.size();
            for (int i = 0; i < size; ++i) {
                vector<int> path = seqQ.front();
                seqQ.pop();
                int current = path.back();
                for (auto& neighbor : adjacency[current]) {
                    if (visited[neighbor] == length - 1) {
                        path.push_back(neighbor);
                        seqQ.push(path);
                        path.pop_back();
                    }
                }
            }
            length--;
        }
        
        int m = seqQ.size();
        vector<vector<string>> res(m);
        int resIdx = 0;
        while (!seqQ.empty()) {
            vector<int> path = seqQ.front();
            seqQ.pop();
            reverse(path.begin(), path.end());
            for (auto node : path) {
                res[resIdx].push_back(idx2word[node]);
            }
            resIdx++;
        }

        return res;
    }
};