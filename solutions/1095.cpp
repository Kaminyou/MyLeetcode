/**
 * // This is the MountainArray's API interface.
 * // You should not implement it, or speculate about its implementation
 * class MountainArray {
 *   public:
 *     int get(int index);
 *     int length();
 * };
 */

class Solution {
public:
    int findInMountainArray(int target, MountainArray &mountainArr) {
        int n = mountainArr.length();
        int left = 0;
        int right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int midValue = mountainArr.get(mid);
            int nextValue = mountainArr.get(mid + 1);
            if (midValue > nextValue) right = mid;
            else left = mid + 1;
        }
        int maxIndex = left;
        if (mountainArr.get(maxIndex) == target) return maxIndex;
        if (mountainArr.get(maxIndex) < target) return -1;
        // find left part
        left = 0;
        right = maxIndex;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int midValue = mountainArr.get(mid);
            if (target <= midValue) right = mid;
            else left = mid + 1;
        }
        if (mountainArr.get(left) == target) return left;
        // find right part
        left = maxIndex;
        right = n - 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            int midValue = mountainArr.get(mid);
            if (target >= midValue) right = mid;
            else left = mid + 1;
        }
        if (mountainArr.get(left) == target) return left;
        return -1;
    }
};