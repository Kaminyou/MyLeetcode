class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        // one pig has ${state} state
        int state = minutesToTest / minutesToDie + 1;
        // state ^ n >= buckets
        // n = ceil(log(state, buckets)) = ceil(log(e, buckets) / log(e, state))
        int res = ceil(log(buckets) / log(state));
        if (pow(state, res - 1) >= buckets) return res - 1; // fp issue
        return res;
    }
};
