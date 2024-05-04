class Solution {
public:
    int wateringPlants(vector<int>& plants, int capacity) {
        int sum = 0;
        int remain = capacity;
        for (int i = 0; i < plants.size(); ++i) {
            if (remain < plants[i]) {
                remain = capacity;
                remain -= plants[i];
                sum += i * 2 + 1;
            }
            else {
                remain -= plants[i];
                sum += 1;
            }
        }
        return sum;
    }
};