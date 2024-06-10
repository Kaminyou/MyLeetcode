class Solution {
public:
    int heightChecker(vector<int>& heights) {
        vector<int> orderedHeights(heights.begin(), heights.end());
        sort(heights.begin(), heights.end());
        int res = 0 ;
        int n = heights.size();
        for (int i = 0; i < n; ++i) {
            if (heights[i] != orderedHeights[i]) res++;
        }
        return res;
    }
};
