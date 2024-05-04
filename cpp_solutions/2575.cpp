class Solution {
public:
    vector<int> divisibilityArray(string word, int m) {
        int n = word.size();
        vector<int> res(n, 0);
        long long sum = 0;
        for (int i = 0; i < n; ++i) {
            sum *= 10;
            sum += (word[i] - '0');
            sum %= m;
            if (sum == 0) {
                res[i] = 1;
            }
        }
        return res;
    }
};