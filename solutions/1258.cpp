class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;
public:
    DisjointSet(int size) {
        parent.resize(size, 0);
        rank.resize(size, 0);
        for (int i = 0; i < size; ++i) parent[i] = i;
    }
    int find(int x) {
        if (x != parent[x]) {
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
    vector<string> res;
    void tokens2string(vector<string>& tokens) {
        int n = tokens.size();
        string ans = "";
        for (int i = 0; i < n; ++i) {
            ans += tokens[i];
            if (i != n - 1) ans += " ";
        }
        res.push_back(ans);
    }
    void backtracking(int curr, vector<string>& tokens, vector<string>& finalTokens, unordered_map<int, vector<string>>& parent2synonyms, DisjointSet* disjointSet, unordered_map<string, int>& string2idx) {
        if (curr == tokens.size()) {
            tokens2string(finalTokens);
            return;
        }
        if (string2idx.find(tokens[curr]) == string2idx.end()) {
            finalTokens.push_back(tokens[curr]);
            backtracking(curr + 1, tokens, finalTokens, parent2synonyms, disjointSet, string2idx);
            finalTokens.pop_back();
        }
        else {
            int parent = disjointSet->find(string2idx[tokens[curr]]);
            for (auto& choice : parent2synonyms[parent]) {
                finalTokens.push_back(choice);
                backtracking(curr + 1, tokens, finalTokens, parent2synonyms, disjointSet, string2idx);
                finalTokens.pop_back();
            }
        }
    }
    vector<string> generateSentences(vector<vector<string>>& synonyms, string text) {
        int index = 0;
        unordered_map<string, int> string2idx;
        for (auto& synonym : synonyms) {
            if (string2idx.find(synonym[0]) == string2idx.end()) {
                string2idx[synonym[0]] = index;
                index++;
            }
            if (string2idx.find(synonym[1]) == string2idx.end()) {
                string2idx[synonym[1]] = index;
                index++;
            }
        }
        DisjointSet* disjointSet = new DisjointSet(index);
        for (auto& synonym : synonyms) {
            int x = string2idx[synonym[0]];
            int y = string2idx[synonym[1]];
            disjointSet->join(x, y);
        }
        
        unordered_map<int, vector<string>> parent2synonyms;
        for (auto& element : string2idx) {
            int parent = disjointSet->find(element.second);
            parent2synonyms[parent].push_back(element.first);
        }
                
        vector<string> tokens;
        string token;
        stringstream ss(text);
        while (getline(ss, token, ' ')) {
            tokens.push_back(token);
        }
        
        vector<string> finalTokens;
        backtracking(0, tokens, finalTokens, parent2synonyms, disjointSet, string2idx);
        sort(res.begin(), res.end());
        return res;
    }
};