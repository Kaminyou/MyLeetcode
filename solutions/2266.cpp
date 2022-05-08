class Solution {
public:
    int countTexts(string pressedKeys) {
        long long mod = 1e9 + 7;
        // precompute for three
        vector<long long> threeNum = {1,2,3};
        vector<long long> threeDP(100001, 0);
        threeDP[0] = 1;
        for (int i = 0; i <= 100000; i++) {
            for (int j = 0; j < threeNum.size(); j++) {
                if (i - threeNum[j] >= 0) {
                    threeDP[i] += threeDP[i - threeNum[j]];
                    threeDP[i] %= mod;
                }
            }
        }
        // precompute for four
        vector<long long> fourNum = {1,2,3,4};
        vector<long long> fourDP(100001, 0);
        fourDP[0] = 1;
        for (int i = 0; i <= 100000; i++) {
            for (int j = 0; j < fourNum.size(); j++) {
                if (i - fourNum[j] >= 0) {
                    fourDP[i] += fourDP[i - fourNum[j]];
                    fourDP[i] %= mod;
                }
            }
        }
        // all
        int index = 0;
        int n = pressedKeys.size();
        long long res = 1;
        while (index < n) {
            char c = pressedKeys[index];
            int start = index;
            while (index + 1 < n && pressedKeys[index + 1] == c) {
                index++;
            }
            int length = index - start + 1;
            if (c == '7' || c == '9') res *= fourDP[length];
            else res *= threeDP[length];
            res %= mod;
            index++;
        }
        return res;
    }
};