class Solution {
public:
    vector<int> amountPainted(vector<vector<int>>& paint) {
        int n = paint.size();
        vector<int> res(n, 0);
        
        map<int, int> paintArea; // start->end
        for (int i = 0; i < n; ++i) {
            int start = paint[i][0];
            int end = paint[i][1];
            // to find the first duplicate chunk
            // find one chunk's start > curr start
            auto it = paintArea.upper_bound(start);
            // check if prev one has duplicated area
            if (it != paintArea.begin()) {
                if (prev(it)->second >= start) {
                    it = prev(it);
                }
            }
            int accum = 0;
            // move until not duplicated
            while (it != paintArea.end() && it->first <= end) {
                start = min(start, it->first);
                end = max(end, it->second);
                accum += it->second - it->first;
                auto curr = it;
                it = next(it);
                paintArea.erase(curr);
            }
            paintArea[start] = end;
            res[i] = end - start - accum;
        }
        return res;
    }
};