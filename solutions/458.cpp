class Solution {
public:
    int poorPigs(int buckets, int minutesToDie, int minutesToTest) {
        // one pig has ${state} state
        int state = minutesToTest / minutesToDie + 1;
        // state ^ n >= buckets
        // n = ceil(log(state, buckets)) = ceil(log(e, buckets) / log(e, state))
        return ceil(log(buckets) / log(state));
    }
};