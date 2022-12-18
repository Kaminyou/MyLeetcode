class Solution {
public:
    int getHeight(int node, vector<int>& path) {
        int cnt = 0;
        while (node != 1) {
            path[cnt] = node;
            cnt++;
            node /= 2;
        }
        path[cnt] = node;
        cnt++;
        reverse(path.begin(), path.begin() + cnt);
        return cnt;
    }
    int parseRes(int query1, int query2, vector<int>& path1, vector<int>& path2) {
        int height1 = getHeight(query1, path1);
        int height2 = getHeight(query2, path2);
        
        int collision = -1;
        int minHeight = min(height1, height2);
        for (int i = 0; i < minHeight; ++i) {
            if (path1[i] == path2[i]) {
                collision = i;
            }
        }
        
        if (collision == -1) return height1 + height2 - 2 + 1;
        return height1 + height2 - 2 - collision * 2 + 1;
    }
    vector<int> cycleLengthQueries(int n, vector<vector<int>>& queries) {
        vector<int> path1(32, 0);
        vector<int> path2(32, 0);
        int m = queries.size();
        vector<int> res(m, -1);
        for (int i = 0; i < m; ++i) {
            res[i] = parseRes(queries[i][0], queries[i][1], path1, path2);
        }
        return res;
    }
};