class Solution {
public:
    int maxDistance(string moves) {
        vector<int> counts(5, 0);
        for (auto& move : moves) {
            if (move == 'U') counts[0]++;
            if (move == 'D') counts[1]++;
            if (move == 'L') counts[2]++;
            if (move == 'R') counts[3]++;
            if (move == '_') counts[4]++;
        }
        int a = abs(counts[0] - counts[1]);
        int b = abs(counts[2] - counts[3]);
        return a + b + counts[4];
    }
};
