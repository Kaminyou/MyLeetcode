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

class Solution {
public:
    int maximumBags(vector<int>& capacity, vector<int>& rocks, int additionalRocks) {
        int n = capacity.size();
        vector<int> left(n, 0);
        for (int i = 0; i < n; ++i) {
            left[i] = capacity[i] - rocks[i];
        }
        sort(left.begin(), left.end());
        int cnt = 0;
        for (int i = 0; i < n && additionalRocks > 0; ++i) {
            int temp = min(left[i], additionalRocks);
            left[i] -= temp;
            additionalRocks -= temp;
            if (left[i] == 0) cnt++;
        }
        return cnt;
    }
};