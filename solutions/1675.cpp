class Solution {
public:
    int minimumDeviation(vector<int>& nums) {
        int minValue = INT_MAX;
        int res = INT_MAX;
        priority_queue<int> pq;
        for (auto num : nums) {
            if (num & 1) {
                num *= 2;
            }
            minValue = min(minValue, num);
            pq.push(num);
        }

        while (pq.top() % 2 == 0) {
            int element = pq.top();
            pq.pop();
            res = min(res, element - minValue);
            element /= 2;
            minValue = min(minValue, element);
            pq.push(element);
        }
        return min(res, pq.top() - minValue);
    }
};