class Solution {
public:
    int peakIndexInMountainArray(vector<int>& A) {
		int left = 1;
        int right = A.size() - 2;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (A[mid] > A[mid - 1] && A[mid] > A[mid + 1]) return mid;
            if (A[mid] > A[mid - 1]) {
                left = mid + 1;
            }
            else {
                right = mid;
            }
        }
        return left;
    }
};

// v2
// class Solution {
// public:
//     int peakIndexInMountainArray(vector<int>& A) {
// 		int left = 0;
//         int right = A.size() - 1;
//         while (left < right) {
//             int mid = left + (right - left) / 2;
//             if (A[mid] > A[mid + 1]) right = mid;
//             else left = mid + 1;
//         } 
//         return left;
//     }
// };