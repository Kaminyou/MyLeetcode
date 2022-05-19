class Solution {
public:
    vector<vector<int>> averageHeightOfBuildings(vector<vector<int>>& buildings) {
        map<int, pair<int, int>> mp; // start or end : height, cnt
        for (auto building : buildings) {
            mp[building[0]].first += building[2];
            mp[building[0]].second += 1;
            mp[building[1]].first -= building[2];
            mp[building[1]].second -= 1;
        }
        vector<vector<int>> res;
        int currCount = 0;
        int currHeightSum = 0;
        int prevAnchor = -1;
        int prevHeight = -1;
        int prevCount = -1;
        for (auto element : mp) {
            auto [anchor, stat] = element;
            auto [height, cnt] = stat;
            currHeightSum += height;
            currCount += cnt;
            
            // flag will be true if avgCurrHeight = avgPrevHeight
            bool flag = false;
            if (prevAnchor != -1) {
                int currAverage = -1;
                if (currCount == 0) {
                    // meet an end => reset
                    res.push_back({prevAnchor, anchor, prevHeight / prevCount});
                    currCount = 0;
                    currHeightSum = 0;
                    prevAnchor = -1;
                    prevHeight = -1;
                    prevCount = -1;
                    continue;
                }
                if (currCount != 0) currAverage = currHeightSum / currCount;
                if (currAverage != prevHeight / prevCount) {
                    res.push_back({prevAnchor, anchor, prevHeight / prevCount});
                }
                else {
                    flag = true;
                }
            }
            // if avgCurrHeight = avgPrevHeight, do no update anchor
            if (!flag) prevAnchor = anchor;
            prevHeight = currHeightSum;
            prevCount = currCount;
        }
        return res;
    }
};