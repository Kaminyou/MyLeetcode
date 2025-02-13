class Solution {
public:
    int minOperations(vector<int>& nums, int k) {
        priority_queue<long long, vector<long long>, greater<long long>> pq;
        for (auto& num : nums) {
            pq.push(num);
        }
        int operations = 0;
        while (pq.size() >= 2) {
            long long element1 = pq.top();
            if (element1 >= k) break;
            pq.pop();
            long long element2 = pq.top();
            pq.pop();
            pq.push(min(element1, element2) * 2 + max(element1, element2));
            operations++;
        }
        long long element1 = pq.top();
        if (!(element1 >= k)) return -1;
        return operations;
    }
};

