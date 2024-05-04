class Solution {
public:
    int countHousePlacements(int n) {
        const long long mod = 1e9 + 7;
        long long houses = 1;
        long long spaces = 1;
        long long total = 2;
        for (int i = 2; i <= n; ++i) {
            houses = spaces;
            spaces = total;
            total = (houses + spaces) % mod;
        }
        return (total * total) % mod;
    }
};