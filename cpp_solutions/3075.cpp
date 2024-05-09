class Solution {
public:
    long long maximumHappinessSum(vector<int>& happiness, int k) {
        long long res = 0;
        priority_queue<int> pq(happiness.begin(), happiness.end());
        int cnt = 0;
        while (k) {
            int temp = pq.top();
            pq.pop();
            res += max(temp - cnt, 0);
            k--;
            cnt++;
        }
        return res;
    }
};
