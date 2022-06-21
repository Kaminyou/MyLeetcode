class Solution {
public:
    int maxDistToClosest(vector<int>& seats) {
        int res = 0;
        int currLocation = 0;
        bool first = true;
        for (int i = 0; i < seats.size(); ++i) {
            if (seats[i] == 1) {
                if (first) {
                    res = max(res, i);
                    currLocation = i;
                    first = false;
                }
                else {
                    int diff = i - currLocation;
                    res = max(res, diff / 2);
                    currLocation = i;
                }
            }
        }
        // last
        res = max(res, static_cast<int>(seats.size()) - currLocation - 1);
        return res;
    }
};