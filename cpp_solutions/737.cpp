class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;
public:
    DisjointSet(int size) {
        parent.resize(size);
        rank.resize(size);
        for (int i = 0; i < size; ++i) parent[i] = i;
    }
    int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]);
        }
        return parent[x];
    }
    void join(int x, int y) {
        int pX = find(x);
        int pY = find(y);
        if (pX == pY) return;
        if (rank[pX] > rank[pY]) {
            parent[pY] = pX;
        }
        else if (rank[pX] < rank[pY]) {
            parent[pX] = pY;
        }
        else {
            parent[pY] = pX;
            rank[pX]++;
        }
    }
    
};
class Solution {
public:
    bool areSentencesSimilarTwo(vector<string>& sentence1, vector<string>& sentence2, vector<vector<string>>& similarPairs) {
        if (sentence1.size() != sentence2.size()) return false;
        
        unordered_map<string, int> word2idx;
        int index = 0;
        for (auto& pair : similarPairs) {
            if (word2idx.find(pair[0]) == word2idx.end()) word2idx[pair[0]] = index++;
            if (word2idx.find(pair[1]) == word2idx.end()) word2idx[pair[1]] = index++;
        }
        
        DisjointSet* disjointSet = new DisjointSet(index);
        for (auto& pair : similarPairs) {
            disjointSet->join(word2idx[pair[0]], word2idx[pair[1]]);
        }
        
        int n = sentence1.size();
        for (int i = 0; i < n; ++i) {
            if (sentence1[i] != sentence2[i]) {
                if (word2idx.find(sentence1[i]) == word2idx.end()) return false;
                if (word2idx.find(sentence2[i]) == word2idx.end()) return false;
                int idx1 = word2idx[sentence1[i]];
                int idx2 = word2idx[sentence2[i]];
                if (disjointSet->find(idx1) != disjointSet->find(idx2)) return false;
            }
        }
        return true;
    }
};