typedef pair<int, int> P;
class Solution {
public:
    vector<int> findClosestElements(vector<int>& arr, int k, int x) {
        int left = 0;
        int right = arr.size() - k;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (x - arr[mid] <= arr[mid + k] - x) right = mid;
            else left = mid + 1;
        }
        vector<int> res;
        for (int i = 0; i < k; ++i) {
            res.push_back(arr[left + i]);
        }
        return res;
    }
};