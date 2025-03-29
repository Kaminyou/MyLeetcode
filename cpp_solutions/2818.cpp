class Solution {
public:
    long long getPower(long long n, long long p){
        long long mod = 1e9 + 7;
        long long res = 1;
        n = n % mod;
        while (p > 0){
            if(p & 1){
                res = (res * n) % mod; 
                p--;
            }
            n = (n * n) % mod; 
            p = p >> 1;
        }
        return res;
    }
    int scoring(int num) {
        int cnt = 0;
        for (int i = 2; i * i <= num; ++i) {
            if (num % i == 0) {
                while (num % i == 0) num /= i;
                cnt++;
            }
            if (num == 1) break;
        }
        if (num >= 2) cnt++;
        return cnt;
    }
    int maximumScore(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> primeScores(n, 0);
        for (int i = 0; i < n; ++i) {
            primeScores[i] = scoring(nums[i]);
        }
        stack<int> st;
        vector<int> left(n, 0);
        left[0] = 0;
        st.push(0);
        for (int i = 1; i < n; ++i) {
            int curr = i;
            while (!st.empty() && primeScores[i] > primeScores[st.top()]) {
                curr = min(curr, left[st.top()]);
                st.pop();
            }
            st.push(i);
            left[i] = curr;
        }
        while (!st.empty()) st.pop();
        vector<int> right(n, 0);
        right[n - 1] = n - 1;
        st.push(n - 1);
        for (int i = n - 2; i >= 0; --i) {
            int curr = i;
            while (!st.empty() && primeScores[i] >= primeScores[st.top()]) {
                curr = max(curr, right[st.top()]);
                st.pop();
            }
            st.push(i);
            right[i] = curr;
        }
        priority_queue<pair<long long, long long>> pq;
        for (int i = 0; i < n; ++i) {
            long long r = right[i] - i + 1;
            long long l = i - left[i];
            long long total = r * (1 + l);
            pq.push({nums[i], total});
        }
        long long res = 1;
        long long mod = 1e9 + 7;
        long long kk = k;
        while (kk > 0) {
            auto [x, total] = pq.top();
            pq.pop();
            res = res * getPower(x, min(kk, total)) % mod;
            kk = kk - min(kk, total);
        }
        return res;
    }
};
