class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        int n = status.size();
        vector<bool> visited(n, false);
        queue<int> q;
        unordered_set<int> waiting;

        for (auto& box : initialBoxes) {
            if (status[box]) q.push(box);
            else waiting.insert(box);
        }

        int res = 0 ;
        while (!q.empty()) {
            int n = q.size();
            while (n--) {
                int box = q.front();
                q.pop();
                res += candies[box];
                visited[box] = true;
                for (auto& key : keys[box]) {
                    if (status[key] == 0 && waiting.count(key)) {
                        q.push(key);
                    }
                    status[key] = 1;
                }
                for (auto& bbox : containedBoxes[box]) {
                    if (status[bbox]) {
                        if (!visited[bbox]) q.push(bbox);
                    }
                    else waiting.insert(bbox);
                }
            }
        }
        return res;
    }
};

