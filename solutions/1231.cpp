class Solution {
public:
    int seperate(const vector<int>& sweetness, int min) {
        int count = 0;
        int sum = 0;
        for (auto sweet : sweetness) {
            sum += sweet;
            if (sum >= min) {
                count++;
                sum = 0;
            }
        }
        return count;
    }
    int maximizeSweetness(vector<int>& sweetness, int k) {
        int sum = 0;
        for (auto sweet : sweetness) sum += sweet;
        int left = 0;
        int right = sum / (k + 1) + 1;
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (seperate(sweetness, mid) < k + 1) right = mid;
            else left = mid + 1;
        }
        return left - 1;
    }
};