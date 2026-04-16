class Solution {
public:
    vector<int> solveQueries(vector<int>& nums, vector<int>& queries) {
        unordered_map<long long, long long> internalIndex2outerindex;
        unordered_map<long long, long long> outerIndex2internalIndex;
        unordered_map<int, vector<int>> num2v;
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            long long num = nums[i];
            int m = num2v[num].size();
            long long internalKey = (num << 20) + m;
            num2v[num].push_back(i);
            internalIndex2outerindex[internalKey] = i;
            outerIndex2internalIndex[i] = internalKey;
        }

        int k = queries.size();
        vector<int> res(k, INT_MAX);
        for (int i = 0; i < k; ++i) {
            int q = queries[i];
            long long num = nums[q];
            if (num2v[num].size() <= 1) continue;
            int m = num2v[num].size();
            long long internalKey = outerIndex2internalIndex[q];
            long long internalIdx = internalKey & ((1LL << 20) - 1);
            long long leftIdx = (internalIdx - 1 + m) % m;
            long long rightIdx = (internalIdx + 1) % m;
            long long leftOutIdx = internalIndex2outerindex[(num << 20) + leftIdx];
            long long rightOutIdx = internalIndex2outerindex[(num << 20) + rightIdx];
            res[i] = min(res[i], (int)abs(leftOutIdx - q));
            res[i] = min(res[i], n - (int)abs(leftOutIdx - q));
            res[i] = min(res[i], (int)abs(rightOutIdx - q));
            res[i] = min(res[i], n - (int)abs(rightOutIdx - q));
        }
        for (int i = 0; i < k; ++i) {
            if (res[i] == INT_MAX) res[i] = -1;
        }
        return res;
    }
};
