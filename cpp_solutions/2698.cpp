class Solution {
public:
    bool _partitionable(int position, int tempSum, int currentSum, int k, string& kS, int ori) {
        if (currentSum + tempSum > ori) return false;
        if (position == kS.size()) {
            return currentSum == ori;
        }
        tempSum *= 10;
        tempSum += kS[position] - '0';
        if (_partitionable(position + 1, tempSum, currentSum, k, kS, ori)) return true;
        if (_partitionable(position + 1, 0, currentSum + tempSum, k, kS, ori)) return true;
        return false;
    }
    bool partitionable(int k, int ori) {
        string kS = to_string(k);
        return _partitionable(0, 0, 0, k, kS, ori);
    }
    int punishmentNumber(int n) {
        int sum = 0;
        for (int i = 1; i <= n; ++i) {
            if (partitionable(i * i, i)) {
                sum += i * i;
            }
        }
        return sum;
    }
};