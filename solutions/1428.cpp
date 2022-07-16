/**
 * // This is the BinaryMatrix's API interface.
 * // You should not implement it, or speculate about its implementation
 * class BinaryMatrix {
 *   public:
 *     int get(int row, int col);
 *     vector<int> dimensions();
 * };
 */

class Solution {
public:
    int leftMostColumnWithOne(BinaryMatrix &binaryMatrix) {
        vector<int> boundary = binaryMatrix.dimensions();
        
        int res = INT_MAX;
        for (int row = 0; row < boundary[0]; row++) {
            int left = 0;
            int right = boundary[1];
            while (left < right) {
                int mid = left + (right - left) / 2;
                if (binaryMatrix.get(row, mid) >= 1) right = mid;
                else left = mid + 1;
            }
            res = min(res, left);
        }

        if (res == boundary[1]) return -1;
        return res;
    }
};