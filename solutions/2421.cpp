// key concept
// gradually build up the graph from the nodes with small value
// so that whenever nodes with larger value are connected with other existing nodes (with smaller values)
// it ensures that any connection of the nodes with larger value would be valid!
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
    int numberOfGoodPaths(vector<int>& vals, vector<vector<int>>& edges) {
        int n = vals.size();
        vector<vector<int>> adjacency(n);
        map<int, vector<int>> value2nodes;
        for (int i = 0; i < n; ++i) {
            value2nodes[vals[i]].push_back(i);
        }
        for (auto& edge : edges) {
            int nodeA = edge[0];
            int nodeB = edge[1];
            // store node with large value -> node with val small value
            // so that we can connect two nodes only when the larger node is considered
            if (vals[nodeA] >= vals[nodeB]) {
                adjacency[nodeA].push_back(nodeB);
            }
            if (vals[nodeA] <= vals[nodeB]) {
                adjacency[nodeB].push_back(nodeA);
            }
        }
        
        DisjointSet* disjointSet = new DisjointSet(n);
        
        int res = 0;
        // from the nodes with small value
        for (auto& element : value2nodes) {
            int value = element.first;
            // connect the corresponding neighbors
            for (auto& node : element.second) {
                for (auto& neighbor : adjacency[node]) {
                    disjointSet->join(node, neighbor);
                }
            }
            // check how many groups are there 
            // and how many nodes with current value are there in each group
            unordered_map<int, int> group2size;
            for (auto& node : element.second) {
                group2size[disjointSet->find(node)]++;
            }
            // case 1: node to itself
            res += element.second.size();
            
            // case 2: in each group, if there are >= two nodes with the current value, count how many pairs will be formed
            for (auto& [groupID, size] : group2size) {
                if (size > 1) {
                    res += (size * (size - 1)) / 2;
                }
            }
        }
        return res;
    }
};