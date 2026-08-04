class Solution {
public:
    bool canReach(vector<int>& start, vector<int>& target) {
        int x = start[0] - target[0];
        int y = start[1] - target[1];
        int diff = abs(x - y);
        return !(diff & 1);
    }
};

