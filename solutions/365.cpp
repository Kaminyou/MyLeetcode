class Solution {
public:
    bool canMeasureWater(int jug1Capacity, int jug2Capacity, int targetCapacity) {
        if (jug1Capacity + jug2Capacity < targetCapacity) return false;
        if (jug1Capacity == targetCapacity) return true;
        if (jug2Capacity == targetCapacity) return true;
        if (jug1Capacity + jug2Capacity == targetCapacity) return true;
        
        int gcd = __gcd(jug1Capacity, jug2Capacity);
        return (targetCapacity % gcd) == 0;
    }
};