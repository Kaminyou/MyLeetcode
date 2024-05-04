class Solution {
public:
    int hIndex(vector<int>& citations) {
        // find a lowest value, which has its value >= its index
        int n = citations.size();
        int left = 0;
        int right = n;
        
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (citations[mid] >= n - mid) right = mid;
            else left = mid + 1;
        }
        return n - left;
    }
};