// PREFIX SUM
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        vector<int> prefix(n + 1, 0);
        // prefix sum of 1 at every index
        for (int i = 1; i <= n; i++) {
            prefix[i] = prefix[i - 1] + (s[i - 1] - '0');
        }
        
        int res = INT_MAX;
        // at each index 
        // [0, index) = 0 || [index, n] = 1
        // # of 1 in left segment + # of 0 in right segment
        // = # of 1 in left segment + (len(right segment) - # of 1 in right segment)
        // = (prefix[i] - prefix[0]) + (n - i - (prefix[n] - prefix[i]))
        for (int i = 0; i <= n; i++) {
            res = min({res, prefix[i] + n - i - (prefix[n] - prefix[i])});
        }
        return res;
    }
};

// GREEDY
class Solution {
public:
    int minFlipsMonoIncr(string s) {
        int n = s.size();
        int count1 = 0;
        int count0 = 0;
        // # flip 0 is bounded by # flip 1
        for (auto c : s) {
            if (c == '0') count0++;
            else count1++;
            count0 = min(count0, count1);
        }
        return count0;
    }
};