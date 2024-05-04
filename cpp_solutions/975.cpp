class Solution {
public:
    int oddEvenJumps(vector<int>& arr) {
        int n = arr.size();
        vector<bool> higher(n, false); // start from odd and to higher (>=)
        vector<bool> lower(n, false); // start from even and to lower (<=)
        map<int, int> val2idx;
        
        higher[n - 1] = lower[n - 1] = true;
        val2idx[arr[n - 1]] = n - 1;
        
        int res = 1;
        for (int i = n - 2; i >= 0; --i) {
            auto hi = val2idx.lower_bound(arr[i]);
            auto lo = val2idx.upper_bound(arr[i]);
            if (hi != val2idx.end()) higher[i] = lower[hi->second];
            if (lo != val2idx.begin()) lower[i] = higher[(--lo)->second];
            
            if (higher[i]) res++;
            val2idx[arr[i]] = i;
        }
        return res;
    }
};