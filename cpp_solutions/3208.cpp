class Solution {
public:
    int numberOfAlternatingGroups(vector<int>& colors, int k) {
        int res = 0;
        int n = colors.size();
        for (int i = 0; i < n; ++i) {
            colors.push_back(colors[i]);
        }
        int right = 0;
        int prev = -1;
        for (int left = 0; left < n; ++left) {
            if (right <= left) {
                right = max(right, left);
                prev = -1;
            }
            while (right - left < k) {
                if (prev == -1) {
                    prev = colors[right];
                    right++;
                }
                else {
                    if ((prev ^ colors[right]) == 0) break;
                    prev = colors[right];
                    right++;
                }
            }
            if (right - left == k) {
                res++;
            }
        }
        return res;
    }
};
