class Solution {
public:
    bool isPossible(vector<int>& target) {
        long long sum = 0;
        priority_queue<long long> pq;
        for (auto& num : target) {
            sum += num;
            pq.push(num);
        }
        while (!pq.empty()) {
            long long num = pq.top();
            pq.pop();
            sum -= num;
            if (sum == 1 || num == 1) return true;
            if (sum == 0 || num < sum || num % sum == 0) return false;
            num %= sum;
            sum += num;
            pq.push(num);
        }
        return true;
    }
};
