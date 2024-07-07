class Solution {
public:
    int numWaterBottles(int numBottles, int numExchange) {
        int res = numBottles;
        int left = numBottles;
        while (left >= numExchange) {
            int newBottle = left / numExchange;
            int leftBottle = left % numExchange;
            res += newBottle;
            left = newBottle + leftBottle;
        }
        return res;
    }
};
