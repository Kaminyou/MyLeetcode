class Solution {
public:
    int numSpecialEquivGroups(vector<string>& words) {
        unordered_set<string> st;
        for (auto& word : words) {
            string even;
            string odd;
            int m = word.size();
            for (int i = 0; i < m; ++i) {
                if (i & 1) odd.push_back(word[i]);
                else even.push_back(word[i]);
            }
            sort(odd.begin(), odd.end());
            sort(even.begin(), even.end());
            st.insert(odd + "#" + even);
        }
        return st.size();
    }
};

class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;
    int remain;
public:
    DisjointSet(int size) {
        parent.resize(size, 0);
        rank.resize(size, 0);
        for (int i = 0; i < size; ++i) parent[i] = i;
        remain = size;
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
        remain--;
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
    int getGroup() {
        return remain;
    }
};
class Solution {
public:
    bool isEquivalent(vector<int>& even1, vector<int>& even2, vector<int>& odd1, vector<int>& odd2) {
        for (int i = 0; i < 26; ++i) {
            if (even1[i] != even2[i]) return false;
            if (odd1[i] != odd2[i]) return false;
        }
        return true;
    }
    int numSpecialEquivGroups(vector<string>& words) {
        int n = words.size();
        vector<vector<int>> evenHash(n, vector<int>(26, 0));
        vector<vector<int>> oddHash(n, vector<int>(26, 0));
        
        for (int i = 0; i < n; ++i) {
            int m = words[i].size();
            for (int j = 0; j < m; ++j) {
                if (j & 1) {
                    oddHash[i][words[i][j] - 'a']++;
                }
                else {
                    evenHash[i][words[i][j] - 'a']++;
                }
            }
        }
        
        DisjointSet* disjointSet = new DisjointSet(n);
        
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if (isEquivalent(evenHash[i], evenHash[j], oddHash[i], oddHash[j])) {
                    disjointSet->join(i, j);
                }
            }
        }
        return disjointSet->getGroup();
    }
};