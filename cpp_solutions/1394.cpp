class Solution {
public:
    int findLucky(vector<int>& arr) {
        vector<int> freqs(501, 0);
        for (auto& num : arr) freqs[num]++;
        int res = -1;
        for (int i = 1; i <= 500; ++i) {
            if (freqs[i] == i) res = max(res, i);
        }
        return res;
    }
};
