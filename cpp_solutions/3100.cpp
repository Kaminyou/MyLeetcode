class Solution {
public:
    int maxBottlesDrunk(int numBottles, int numExchange) {
        int res = numBottles;
        while (numBottles >= numExchange) {
            numBottles -= numExchange;
            numBottles += 1;
            res += 1;
            numExchange++;
        }
        return res;
    }
};
