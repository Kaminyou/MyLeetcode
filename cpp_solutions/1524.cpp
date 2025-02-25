class Solution {
public:
    int numOfSubarrays(vector<int>& arr) {
        long long res = 0;
        long long mod = 1e9 + 7;
        vector<long long> hash(2, 0);
        hash[0] = 1;
        long long curr = 0;
        for (auto& num : arr) {
            curr += num;
            hash[curr & 1] += 1;
            hash[curr & 1] %= mod;
            res += hash[(curr & 1) ^ 1];
            res %= mod;
        }
        return res;
    }
};

