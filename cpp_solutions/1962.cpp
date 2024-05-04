class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        int sum = accumulate(piles.begin(), piles.end(), 0);
        priority_queue<int> pq(piles.begin(), piles.end());
        while (k--) {
            int t = pq.top();
            pq.pop();
            sum -= t / 2;
            pq.push(t - t / 2);
        }
        
        return sum;
    }
};

class Solution {
public:
    int minStoneSum(vector<int>& piles, int k) {
        priority_queue<int> pq;
        int sum = 0;
        for (auto& pile : piles) {
            sum += pile;
            pq.push(pile);
        }
        while (k--) {
            int maxOne = pq.top();
            pq.pop();
            int remove = maxOne / 2;
            sum -= remove;
            pq.push(maxOne - remove);
        }
        return sum;
    }
};