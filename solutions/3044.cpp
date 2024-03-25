class Solution {
public:
    unordered_map<int, bool> mp;
    bool isPrime(int num) {
        if (mp.count(num)) return mp[num];
        if (num < 2) return false;
        if (num == 2) return true;
        if (num % 2 == 0) return false;
        for (int i = 3; i * i <= num; i += 2) {
            if (num % i == 0) return false;
        }
        return mp[num] = true;
    }
    vector<pair<int, int>> directions = {{0, 1}, {1, 1}, {1, 0}, {1, -1}, {0, -1}, {-1, -1}, {-1, 0}, {-1, 1}};
    unordered_map<int, int> counts;
    int mostFrequentPrime(vector<vector<int>>& mat) {
        int m = mat.size();
        int n = mat[0].size();
        int res = -1;
        int maxCnt = 0;
        for (int i = 0; i < m; ++i) {
            for (int j = 0; j < n; ++j) {
                for (auto direction : directions) {
                    bool okay = true;
                    int num = mat[i][j];
                    int currentX = i;
                    int currentY = j;
                    while (okay) {
                        currentX += direction.first;
                        currentY += direction.second;
                        if (currentX < 0 || currentY < 0 || currentX >= m || currentY >= n) break;
                        num *= 10;
                        num += mat[currentX][currentY];
                        if (isPrime(num)) {
                            counts[num]++;
                        }
                    }
                }
            }
        }
        for (auto [num, cnt] : counts) {
            if (cnt == maxCnt) {
                res = max(res, num);
            }
            if (cnt > maxCnt) {
                maxCnt = cnt;
                res = num;
            }
        }
        return res;
    }
};
