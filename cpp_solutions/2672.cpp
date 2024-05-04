class Solution {
public:
    vector<int> colorTheArray(int n, vector<vector<int>>& queries) {
        int m = queries.size();
        vector<int> res(m, 0);
        if (m == 1) return res;
        vector<int> nums(n, 0);
        int count = 0;
        for (int i = 0; i < m; ++i) {
            int index = queries[i][0];
            int color = queries[i][1];
            int currentColor = nums[index];
            if (index > 0) {
                int preColor = nums[index - 1];
                if (currentColor == preColor && currentColor != 0) count--;
            }
            if (index < n - 1) {
                int postColor = nums[index + 1];
                if (currentColor == postColor && currentColor != 0) count--;
            }
            
            nums[index] = color;
            if (index > 0) {
                int preColor = nums[index - 1];
                if (color == preColor && color != 0) count++;
            }
            if (index < n - 1) {
                int postColor = nums[index + 1];
                if (color == postColor && color != 0) count++;
            }
            res[i] = count;
        }
        return res;
    }
};