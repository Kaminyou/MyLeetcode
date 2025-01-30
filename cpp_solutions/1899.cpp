class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        vector<int> init = {0, 0, 0};
        for (auto& triplet : triplets) {
            bool okay = true;
            for (int i = 0; i < 3; ++i) {
                if (triplet[i] > target[i]) okay = false;
            }
            if (!okay) continue;
            for (int i = 0; i < 3; ++i) init[i] = max(init[i], triplet[i]);
        }
        for (int i = 0; i < 3; ++i) {
            if (target[i] != init[i]) return false;
        }
        return true;
    }
};

