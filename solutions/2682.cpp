class Solution {
public:
    vector<int> circularGameLosers(int n, int k) {
        vector<bool> isPassed(n, false);
        isPassed[0] = true;
        int current = 0;
        int time = 1;
        while (true) {
            current += time * k;
            current %= n;
            if (isPassed[current]) break;
            isPassed[current] = true;
            time += 1;
        }
        vector<int> res;
        for (int i = 0; i < n; ++i) {
            if (!isPassed[i]) res.push_back(i + 1);
        }
        return res;
    }
};