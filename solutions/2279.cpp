class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        vector<int> empty;
        int count = 0;
        int n = capacity.size();
        for (int i = 0; i < n; ++i) {
            if (capacity[i] == rocks[i]) count++;
            else {
                empty.push_back(capacity[i] - rocks[i]);
            }
        }
        sort(empty.begin(), empty.end());
        for (auto element : empty) {
            if (element <= additionalRocks) {
                additionalRocks -= element;
                count++;
            }
        }
        return count;
    }
};