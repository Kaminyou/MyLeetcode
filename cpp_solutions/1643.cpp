class Solution {
public:
    int combination(int n, int k) {
        // C(n, k)
        if (k > n) return 0;
        if (k * 2 > n) k = n-k;
        if (k == 0) return 1;

        int result = n;
        for (int i = 2; i <= k; ++i) {
            result *= (n-i+1);
            result /= i;
        }
        return result;
    }
    string kthSmallestPath(vector<int>& destination, int k) {
        int hCount = destination[1];
        int vCount = destination[0];
        int totalCount = hCount + vCount;
        string res = "";
        while (totalCount && hCount && vCount) {
            int hCombine = combination(totalCount - 1, vCount);
            int vCombine = combination(totalCount - 1, vCount - 1);
            if (k <= hCombine) {
                res.push_back('H');
                hCount--;
                totalCount--;
            }
            else {
                k -= hCombine;
                res.push_back('V');
                vCount--;
                totalCount--;
            }
        }
        while (hCount) {
            res.push_back('H');
            hCount--;
        }
        while (vCount) {
            res.push_back('V');
            vCount--;
        }
        return res;
    }
};
// HHHVV 5, 2 (select V)
// H start -> left = C(4,2) = 6
// V start -> left = C(4,1) = 4
