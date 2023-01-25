class Solution {
public:
    long long countGood(vector<int>& nums, int k) {
        long long res = 0;
        unordered_map<int, int> countElement;
        
        int n = nums.size();
        long long count = 0;
        int right = 0;
        for (int left = 0; left < n; ++left) {
            // interval [left, right)
            while (count < k && right < n) {
                long long originCnt = static_cast<long long>(countElement[nums[right]]);
                countElement[nums[right]]++;
                count -= (originCnt * (originCnt - 1)) / 2;
                count += (originCnt * (originCnt + 1)) / 2;
                right++;
            }
            if (right > left && count >= k) res += n - right + 1;
            long long originCnt = static_cast<long long>(countElement[nums[left]]);
            count -= (originCnt * (originCnt - 1)) / 2;
            count += ((originCnt  - 1)* (originCnt - 2)) / 2;
            countElement[nums[left]]--;
        }
        return res;
    }
};