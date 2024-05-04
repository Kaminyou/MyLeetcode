class Solution {
public:
    vector<int> constructRectangle(int area) {
        vector<int> res = {area, 1};
        for (int i = 2; i * i <= area; ++i) {
            if (area % i == 0) {
                res = {area / i, i};
            }
        }
        return res;
    }
};