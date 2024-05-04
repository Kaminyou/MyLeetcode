/**
 * // This is the ArrayReader's API interface.
 * // You should not implement it, or speculate about its implementation
 * class ArrayReader {
 *   public:
 *     int get(int index);
 * };
 */

class Solution {
public:
    int search(const ArrayReader& reader, int target) {
        int left = 0;
        int right = 10000;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int res = reader.get(mid);
            if (res >= target) right = mid;
            else left = mid + 1;
        }
        int res = reader.get(left);
        if (res == target) return left;
        return -1;
    }
};