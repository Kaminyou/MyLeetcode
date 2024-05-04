class Solution {
public:
    int distance(vector<int>& v1, vector<int>& v2) {
        return abs(v1[0] - v2[0]) + abs(v1[1] - v2[1]);
    }
    int minDistance(int height, int width, vector<int>& tree, vector<int>& squirrel, vector<vector<int>>& nuts) {
        int n = nuts.size();
        vector<int> nut2tree(n, 0);
        vector<int> nut2squirrel(n, 0);
        
        int sum = 0;
        for (int i = 0; i < n; ++i) {
            nut2tree[i] = distance(nuts[i], tree);
            nut2squirrel[i] = distance(nuts[i], squirrel);
            sum += nut2tree[i] * 2;
        }
        
        int res = INT_MAX;
        for (int i = 0; i < n; ++i) {
            res = min(res, sum - nut2tree[i] + nut2squirrel[i]);
        }
        return res;
        
    }
};
// {nut <-> tree} * 2 + {nut <-> tree} * 1 + squirrel <-> nut
// => all - {nut <-> tree} * 1 + squirrel <-> nut