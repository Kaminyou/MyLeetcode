class Solution {
public:
    int numPairsDivisibleBy60(vector<int>& time) {
        vector<int> counting(60, 0);
        for (auto& t : time) {
            counting[t % 60]++;
        }
        
        long long count = 0;
        for (int i = 1; i <= 29; ++i) {
            count += (counting[i] * counting[60 - i]);
        }
        
        if (counting[30] >= 2) count += ((long long)counting[30] * (counting[30] - 1)) / 2;
        if (counting[0] >= 2) count += ((long long)counting[0] * (counting[0] - 1)) / 2;
        return count;
    }
    
};