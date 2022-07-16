class Solution {
public:
    int longestSubarray(vector<int>& nums, int limit) {
        // max q
        deque<int> maxQ;
        // min q
        deque<int> minQ;
        
        int res = 0;
        int left = 0;
        for (int right = 0; right < nums.size(); ++right) {
            while (!maxQ.empty() && nums[right] >= nums[maxQ.back()]) maxQ.pop_back();
            maxQ.push_back(right);
            while (!minQ.empty() && nums[right] <= nums[minQ.back()]) minQ.pop_back();
            minQ.push_back(right);
            
            while (!maxQ.empty() && !minQ.empty() && nums[maxQ.front()] - nums[minQ.front()] > limit) {
                left++;
                while (maxQ.front() < left) maxQ.pop_front();
                while (minQ.front() < left) minQ.pop_front();
            }
            res = max(res, right - left + 1);
        }
        return res;
    }
};