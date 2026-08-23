class Solution {
public:
    bool sumGame(string num) {
        int n = num.size();
        int cntLeft = 0;
        int cntRight = 0;
        int sumLeft = 0;
        int sumRight = 0;
        for (int i = 0; i < n / 2; ++i) {
            if (num[i] == '?') cntLeft++;
            else sumLeft += (num[i] - '0');
        }
        for (int i = n / 2; i < n; ++i) {
            if (num[i] == '?') cntRight++;
            else sumRight += (num[i] - '0');
        }
        int diff = abs(cntLeft - cntRight);
        if (diff == 0) {
            if (sumLeft == sumRight) return false;
            return true;
        }
        if (cntLeft > cntRight) {
            swap(cntLeft, cntRight);
            swap(sumLeft, sumRight);
        }
        // cntRight > cntLeft
        if (sumRight >= sumLeft) return true;
        // diff to fill into right; sumRight < sumLeft
        int bobQuota = diff / 2;
        // Alice fill all 0
        if (sumLeft - sumRight > 9 * bobQuota) return true;
        // Alice fill all 9
        if (sumRight + (diff - bobQuota) * 9 > sumLeft) return true;
        return false;
    }
};

