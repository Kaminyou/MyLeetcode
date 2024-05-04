class Solution {
public:
    vector<int> prefixSum;
    int sum = 0;
    Solution(vector<int>& w) {
        prefixSum.push_back(0);
        for (auto& num : w) {
            sum += num;
            prefixSum.push_back(sum);
        }
    }
    
    int binarySearch(int query) {
        int left = 0;
        int right = prefixSum.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            if (prefixSum[mid] > query) right = mid;
            else left = mid + 1;
        }
        return left;
    }
    
    int pickIndex() {
        int rnd = rand() % sum;
        int index = binarySearch(rnd) - 1;
        return index;
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(w);
 * int param_1 = obj->pickIndex();
 */