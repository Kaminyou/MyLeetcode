class Solution {
public:
    int maxJump(vector<int>& stones) {
        int n = stones.size();
        int a = 0;
        int b = 0;
        int maxDistance = 0;
        for (int i = 1; i < n; ++i) {
            int aToNext = stones[i] - a;
            int bToNext = stones[i] - b;
            if (aToNext > bToNext) {
                maxDistance = max(maxDistance, aToNext);
                a = stones[i];
            }
            else {
                maxDistance = max(maxDistance, bToNext);
                b = stones[i];
            }
        }
        return maxDistance;
    }
};