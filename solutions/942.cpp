class Solution {
public:
    vector<int> diStringMatch(string s) {
        int n = s.size() + 1;
        vector<int> res(n, 0);
        int left = 0;
        int right = n - 1;
        for (int i = 0; i < n - 1; ++i) {
            if (s[i] == 'I') {
                res[i] = left;
                left++;
            }
            else {
                res[i] = right;
                right--;
            }
        }
        res[n - 1] = left;
        return res;
    }
};
