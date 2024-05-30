class Solution {
public:
    int countTriplets(vector<int>& arr) {
        int n = arr.size();
        vector<int> prefix(n + 1, 0);
        int curr = 0;
        for (int i = 0; i < n; ++i) {
            curr ^= arr[i];
            prefix[i + 1] = curr;
        }
        int res = 0;
        for (int i = 0; i < n; ++i) {
            for (int j = i + 1; j < n; ++j) {
                if ((prefix[j + 1] ^ prefix[i]) == 0) res += (j - i);
            }
        }
        return res;
    }
};
