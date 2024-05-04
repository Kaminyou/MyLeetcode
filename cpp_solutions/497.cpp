class Solution {
public:
    vector<vector<int>> *rects;
    map<int, int> num2idx;
    int sum = 0;
    Solution(vector<vector<int>>& rects) {
        this->rects = &rects;
        for (int i = 0; i < rects.size(); ++i) {
            int x1 = rects[i][0];
            int y1 = rects[i][1];
            int x2 = rects[i][2];
            int y2 = rects[i][3];
            sum += (x2 - x1 + 1) * (y2 - y1 + 1);
            num2idx[sum] = i;
        }
    }
    
    vector<int> pick() {
        int randNum = rand() % sum;
        int randIdx = num2idx.upper_bound(randNum)->second;

        int x1 = (*rects)[randIdx][0];
        int y1 = (*rects)[randIdx][1];
        int x2 = (*rects)[randIdx][2];
        int y2 = (*rects)[randIdx][3];
        int randW = rand() % (x2 - x1 + 1);
        int randH = rand() % (y2 - y1 + 1);
        return {x1 + randW, y1 + randH};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(rects);
 * vector<int> param_1 = obj->pick();
 */