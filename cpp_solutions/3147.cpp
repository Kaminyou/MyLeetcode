class Solution {
public:
    int maximumEnergy(vector<int>& energy, int k) {
        int res = INT_MIN;
        int n = energy.size();
        for (int i = 0; i < k; ++i) {
            int cur = n - i - 1;
            int sum = 0;
            while (cur >= 0) {
                sum += energy[cur];
                res = max(res, sum);
                cur -= k;
            }
        }
        return res;
    }
};
