class Solution {
public:
    vector<int> missingRolls(vector<int>& rolls, int mean, int n) {
        int m = rolls.size();
        int sum = mean * (m + n);
        for (auto& roll : rolls) sum -= roll;
        if (sum < n) return {};
        if (sum > n * 6) return {};
        int avg = sum / n;
        vector<int> res(n, avg);
        sum -= n * avg;
        int index = 0;
        while (sum--) {
            res[index]++;
            index++;
        }
        return res;
    }
};

