class Solution {
public:
    int minimumRecolors(string blocks, int k) {
        int left = 0;
        int n = blocks.size();
        int w = 0;
        int b = 0;
        int res = INT_MAX;
        for (int right = 0; right < n; ++right) {
            if (blocks[right] == 'W') w++;
            else b++;
            if (right - left + 1 > k) {
                if (blocks[left] == 'W') w--;
                else b--;
                left++;
            }
            
            if (right - left + 1 == k) {
                res = min(res, w);
            }
        }
        return res;
    }
};