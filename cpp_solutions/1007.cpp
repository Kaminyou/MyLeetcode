class Solution {
public:
    int minDominoRotations(vector<int>& tops, vector<int>& bottoms) {
        int res = INT_MAX;
        int n = tops.size();
        for (int target = 1; target <= 6; ++target) {
            int cnt = 0;
            bool flag = true;
            for (int i = 0; i < n; ++i) {
                if (tops[i] == target) continue;
                else if (bottoms[i] == target) cnt++;
                else {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                res = min(res, cnt);
            }
            cnt = 0;
            flag = true;
            for (int i = 0; i < n; ++i) {
                if (bottoms[i] == target) continue;
                else if (tops[i] == target) cnt++;
                else {
                    flag = false;
                    break;
                }
            }
            if (flag) {
                res = min(res, cnt);
            }
        }
        return res == INT_MAX ? -1 : res;
    }
};
