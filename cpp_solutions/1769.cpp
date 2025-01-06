class Solution {
public:
    vector<int> minOperations(string boxes) {
        int left = 0;
        int right = 0;
        int n = boxes.size();
        vector<int> res(n, 0);
        for (int i = 1; i < n; ++i) {
            if (boxes[i] == '1') {
                right++;
                res[0] += i;
            }
        }
        for (int i = 1; i < n; ++i) {
            res[i] = res[i - 1];
            res[i] -= right;
            if (boxes[i] == '1') {
                right--;
            }
            if (boxes[i - 1] == '1') {
                left++;
            }
            res[i] += left;
        }
        return res;
    }
};

