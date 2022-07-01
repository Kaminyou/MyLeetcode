class Solution {
public:
    vector<int> getModifiedArray(int length, vector<vector<int>>& updates) {
        vector<int> difference(length, 0);
        for (auto& update : updates) {
            difference[update[0]] += update[2];
            if (update[1] + 1 < length) difference[update[1] + 1] -= update[2];
        }
        for (int i = 1; i < length; ++i) {
            difference[i] += difference[i - 1];
        }
        return difference;
    }
};
//                -1-0 0-1 1-2 2-3 3-4
// difference     [0,  0,  0,  0,  0] 
// update[1,3,2]  [0,  2,  0,  0,  -2]
// update[2,4,3]  [0,  2,  3,  0,  -2]
// update[0,2,-2] [-2, 2,  3,  2,  -2]
// => [-2, 0, 3, 5, 3]