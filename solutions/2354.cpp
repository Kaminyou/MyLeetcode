class Solution {
public:
    long long countExcellentPairs(vector<int>& nums, int k) {
        unordered_set<int> numberHash;
        vector<int> bitcounts;
        for (auto& num : nums) {
            if (numberHash.find(num) != numberHash.end()) continue;
            int bits = __builtin_popcount(num);
            bitcounts.push_back(bits);
            numberHash.insert(num);
        }
        
        sort(bitcounts.begin(), bitcounts.end());
        int n = bitcounts.size();

        long long res = 0;
        
        for (int i = 0; i < n; ++i) {
            int target = k - bitcounts[i];
            auto it = lower_bound(bitcounts.begin(), bitcounts.end(), target);
            long long plus = n - (it - bitcounts.begin());
            res += plus;
        }
        return res;
    }
};