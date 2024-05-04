class DisjointSet {
private:
    vector<int> parent;
    vector<int> rank;
public:
    DisjointSet(int n) {
        parent.resize(n, 0);
        rank.resize(n, 0);
        for (int i = 0; i < n; ++i) parent[i] = i;
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
        else if (rank[pY] > rank[pX]) {
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
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
        unordered_map<string, int> mail2idx;
        unordered_map<int, string> idx2mail;
        unordered_map<int, string> idx2name;
        
        int index = 0;
        for (auto& account : accounts) {
            int n = account.size();
            string name = account[0];
            for (int i = 1; i < n; ++i) {
                if (mail2idx.find(account[i]) == mail2idx.end()) {
                    mail2idx[account[i]] = index;
                    idx2mail[index] = account[i];
                    idx2name[index] = name;
                    index++;
                }
            }
        }
        
        DisjointSet* disjointSet = new DisjointSet(index);
        for (auto& account : accounts) {
            int n = account.size();
            for (int i = 2; i < n; ++i) {
                disjointSet->join(mail2idx[account[i - 1]], mail2idx[account[i]]);
            }
        }
        
        unordered_map<int, vector<int>> grouping;
        for (int i = 0; i < index; ++i) {
            int parent = disjointSet->find(i);
            grouping[parent].push_back(i);
        }
        
        vector<vector<string>> res;
        for (auto& group : grouping) {
            int mailFirstIdx = group.second[0];
            vector<string> accountSingle = {idx2name[mailFirstIdx]};
            for (auto& mailIdx : group.second) {
                accountSingle.push_back(idx2mail[mailIdx]);
            }
            sort(accountSingle.begin() + 1, accountSingle.end());
            res.push_back(accountSingle);
        }
        return res;
    }
};
