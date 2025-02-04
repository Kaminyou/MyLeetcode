typedef pair<int, int> P;
class Solution {
public:
    vector<int> int2digits(int x) {
        vector<int> temp;
        while (x) {
            int digit = x % 10;
            x /= 10;
            temp.push_back(digit);
        }
        reverse(temp.begin(), temp.end());
        return temp;
    }
    int digits2int(vector<int>& digits) {
        int n = digits.size();
        int factor = 1;
        int res = 0;
        for (int i = n - 1; i >= 0; --i) {
            res += digits[i] * factor;
            factor *= 10;
        }
        return res;
    }
    int minOperations(int n, int m) {
        vector<bool> isPrime(10000, true);
        isPrime[1] = false;
        for (int i = 2; i < 10000; ++i) {
            if (!isPrime[i]) continue;
            for (int j = 2; i * j < 10000;++j) {
                isPrime[i * j] = false;
            }
        }
        if (isPrime[n]) return -1;
        
        unordered_map<int, int> visited;
        priority_queue<P, vector<P>, greater<P>> pq;
        
        pq.push({n, n});
        while (!pq.empty()) {
            P node = pq.top();
            pq.pop();
            if (node.second == m) return node.first;
            if (visited.find(node.second) != visited.end()) continue;
            visited[node.second] = node.first;
            int curr = node.first;
            
            vector<int> digits = int2digits(node.second);
            int n = digits.size();
            for (int i = 0; i < n; ++i) {
                if (digits[i] < 9) {
                    digits[i]++;
                    int next = digits2int(digits);
                    if (visited.find(next) == visited.end() && !isPrime[next]){
                        pq.push({curr + next, next});
                    }
                    digits[i]--;
                }
                if (digits[i] > 0) {
                    digits[i]--;
                    int next = digits2int(digits);
                    if (visited.find(next) == visited.end() && !isPrime[next]){
                        pq.push({curr + next, next});
                    }
                    digits[i]++;
                }
            }
        }
        return -1;
    }
};
