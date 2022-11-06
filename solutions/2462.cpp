typedef pair<int, int> P;
class Solution {
public:
    long long totalCost(vector<int>& costs, int k, int candidates) {
        int n = costs.size();
        long long res = 0;
        priority_queue<P, vector<P>, greater<P>> pq;
        int left = candidates - 1;
        int right = n - candidates;
        
        for (int i = 0; i <= min(left, n - 1); ++i) {
            pq.push({costs[i], i});
        }
        
        for (int i = max(left + 1, right); i < n; ++i) {
            pq.push({costs[i], i});
        }
        left++;
        right--;
        
        while (k--) {
            res += pq.top().first;
            int index = pq.top().second;
            pq.pop();
            if (left <= right) {
                if (index <= left) {
                    
                    pq.push({costs[left], left});
                    left++;
                }
                else {
                    
                    pq.push({costs[right], right});
                    right--;
                }
            }
        }

        return res;
    }
};
