class Solution {
public:
    long long bias = 1 << 11;
    long long pack2(long long a, long long b) {
        return ((a + bias) << 16) + (b + bias);
    }
    long long pack3(long long a, long long b, long long c) {
        return ((a + bias) << 46) + ((b + bias) << 30) + (c + bias * bias);
    }
    long long pack4(long long a, long long b, long long c, long long d) {
        return ((a + bias) << 48) + ((b + bias) << 32) + ((c + bias) << 16) + (d + bias);
    }
    int countTrapezoids(vector<vector<int>>& points) {
        int n = points.size();
        unordered_map<long long, int> slopeMp, lineMp, midMp, midSlopeMp;
        int res = 0;
        for (int i = 0; i < n - 1; ++i) {
            int x0 = points[i][0];
            int y0 = points[i][1];
            for (int j = i + 1; j < n; ++j) {
                int x1 = points[j][0];
                int y1 = points[j][1];

                int slopeA = x1 - x0;
                int slopeB = y1 - y0;
                int intersect = x1 * y0 - y1 * x0;

                int slopeGcd = __gcd(slopeA, slopeB);
                int lineGcd = __gcd(slopeGcd, intersect);

                long long slope = pack2(slopeA / slopeGcd, slopeB / slopeGcd);
                long long line = pack3(slopeA / lineGcd, slopeB / lineGcd, intersect / lineGcd);
                long long mid = pack2(x0 + x1, y0 + y1);
                long long midSlope = pack4(x0 + x1, y0 + y1, slopeA / slopeGcd, slopeB / slopeGcd);
                res += slopeMp[slope];
                res -= lineMp[line];
                res -= midMp[mid];
                res += midSlopeMp[midSlope];

                slopeMp[slope]++;
                lineMp[line]++;
                midMp[mid]++;
                midSlopeMp[midSlope]++;
            }
        }
        return res;
    }
};
