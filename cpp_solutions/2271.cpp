class Solution {
public:
    int maximumWhiteTiles(vector<vector<int>>& tiles, int carpetLen) {
        int n = tiles.size();
        sort(tiles.begin(), tiles.end());
        
        // set boundary for the lower_bound
        int boundary = tiles[tiles.size() - 1][0];

        // map: start -> (end, index)
        map<int, pair<int, int>> mp;
        for (int i = 0; i < n; i++) {
            mp[tiles[i][0]] = make_pair(tiles[i][1], i);
        }

        // prefixSum for each interval
        vector<int> prefixSum(n + 1, 0);
        for (int i = 1; i <= n; i++) {
            prefixSum[i] = prefixSum[i - 1] + (tiles[i - 1][1] - tiles[i - 1][0] + 1); 
        }
        
        // start to iterate each interval
        int res = 0;
        for (int i = 0; i < n; i++) {
            // get the current interval's start point
            // expand it with carpetLen
            int start = tiles[i][0];
            int end = start + carpetLen - 1; // inclusive

            // if the current interval is longer than the carpetLen
            if (end <= tiles[i][1]) {
                res = max(res, end - start + 1);
                continue;
            }
            
            // if the end is over the boundary set before
            if (end > boundary) {
                res = max(res, prefixSum[n] - prefixSum[i]);
                continue;
            }

            // get the interval with binary seaerch
            // whose start point >= current end
            int sum;
            auto it = mp.lower_bound(end);
            
            // case 1: touch the end
            if ((*it).first <= end) {
                int findIdx = (*it).second.second;
                int currIdx = i;
                sum = prefixSum[findIdx] - prefixSum[currIdx] + (end - (*it).first + 1);
            }
            else {
                // move back
                it--;
                int findIdx = (*it).second.second;
                int currIdx = i;
                // case 2: >= end
                if ((*it).second.first >= end) {
                    sum = prefixSum[findIdx] - prefixSum[currIdx] + (end - (*it).first + 1);
                }
                // case 3: < end
                else {
                    sum = prefixSum[findIdx + 1] - prefixSum[currIdx];
                }
            }
            res = max(res, sum);
        }
        return res;
    }
};