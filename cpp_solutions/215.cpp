class Solution {
public:
    int findKthLargest(vector<int>& nums, int k) {
        priority_queue<int, vector<int>, greater<int>> pq;
        for (auto& num : nums) {
            pq.push(num);
            while (pq.size() > k) {
                pq.pop();
            }
        }
        return pq.top();
    }
};