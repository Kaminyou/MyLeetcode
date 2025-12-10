class Solution {
public:
    int countPermutations(vector<int>& complexity) {
        long long res = 1;
        long long mod = 1e9 + 7;
        int first = complexity[0];
        int n = complexity.size();
        for (int i = 1; i < n; ++i) {
            if (complexity[i] <= first) return 0;
            res *= (long long)i;
            res %= mod;
        }
        return res;
    }
};
// if any number <= first -> 0
// else permute all later
