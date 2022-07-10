class Solution {
public:
    vector<long long> maximumEvenSplit(long long finalSum) {
        vector<long long> res;
        if (finalSum & 1) return res;
        
        long long current = 2;
        long long sum = 0;
        while (sum + current <= finalSum) {
            res.push_back(current);
            sum += current;
            current += 2;
        }
        long long remain = finalSum - sum;
        res[res.size() - 1] += remain;
        return res;
    }
};