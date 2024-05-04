class Solution {
public:
    int maximizeWin(vector<int>& prizePositions, int k) {
        int n = prizePositions.size();
        int start = prizePositions[0];
        int end = prizePositions[n - 1];
        if (end - start <= k * 2) return n;
        
        vector<pair<int, int>> v;
        int index = 0;
        while (index < n) {
            int s = index;
            int pos = prizePositions[s];
            while (index + 1 < n && prizePositions[index + 1] == pos) index++;
            int count = index - s + 1;
            v.push_back({pos, count});
            index++;
        }
        
        int m = v.size();
        vector<int> leftDP(m, 0);
        int left = 0;
        int sum = 0;
        for (int right = 0; right < m; ++right) {
            sum += v[right].second;
            while (v[right].first - v[left].first > k) {
                sum -= v[left].second;
                left++;
            }
            if (right - 1 >= 0) leftDP[right] = max(leftDP[right - 1], sum);
            else leftDP[right] = sum;
        }
        
        
        vector<int> rightDP(m, 0);
        int r = m - 1;
        sum = 0;
        for (int l = m - 1; l >= 0; --l) {
            sum += v[l].second;
            while (v[r].first - v[l].first > k) {
                sum -= v[r].second;
                r--;
            }
            if (l + 1 <= m - 1) rightDP[l] = max(rightDP[l + 1], sum);
            else rightDP[l] = sum;
        }

        int res = 0;
        for (int i = 0; i < m - 1; ++i) {
            res = max(res, leftDP[i] + rightDP[i + 1]);
        }
        return res;
    }
};
