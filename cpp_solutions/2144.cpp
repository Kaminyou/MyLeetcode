class Solution {
public:
    int minimumCost(vector<int>& cost) {
        sort(cost.begin(), cost.end(), greater<int>());
        int counter = 0;
        int res = 0;
        for (auto& c : cost) {
            counter++;
            if (counter == 3) {
                counter = 0;
            }
            else {
                res += c;
            }
        }
        return res;
    }
};
