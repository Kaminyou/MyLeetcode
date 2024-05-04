class Solution {
public:
    int separate(const vector<int>& sweetness, int min) {
        // separate chunks by min value
        // if min too large => chunks decrease
        // if min too small => chunks increase
        // want to find min that # of chunks >= k + 1
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
        // +1 : [1,2,2,1,2,2,1,2,2] with k = 2
        // if no +1 => right = 5, chunks max = 3 would not < (k+1) = 3
        // should make right 6 so that chunks can be less than 3
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (separate(sweetness, mid) < k + 1) right = mid;
            else left = mid + 1;
        }
        // now left is the largest value make # of chunck < k + 1
        // so left - 1 => chunks >= k + 1
        return left - 1;
    }
};