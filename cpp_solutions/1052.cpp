class Solution {
public:
    int maxSatisfied(vector<int>& customers, vector<int>& grumpy, int minutes) {
        int base = 0;
        int n = customers.size();
        for (int i = 0; i < n; ++i) {
            if (grumpy[i] == 0) base += customers[i];
        }
        int left = 0;
        int plus = 0;
        int res = base;
        for (int right = 0; right < n; ++right) {
            if (grumpy[right] == 1) plus += customers[right];
            while (right - left + 1 > minutes) {
                if (grumpy[left] == 1) plus -= customers[left];
                left++;
            }
            res = max(res, base + plus);
        }
        return res;
    }
};