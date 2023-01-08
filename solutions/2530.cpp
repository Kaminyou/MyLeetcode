class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
        long long sum = 0;
        priority_queue<int> pq;
        for (auto& num : nums) pq.push(num);
        while (k) {
            int maxVal = pq.top();
            pq.pop();
            bool isDivided = (maxVal % 3 == 0);
            int toStore = maxVal / 3;
            if (!isDivided) toStore++;
            pq.push(toStore);
            sum += (maxVal);
            k--;
        }
        return sum;
    }
};