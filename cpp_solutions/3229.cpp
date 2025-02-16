class Solution {
public:
    long long minimumOperations(vector<int>& nums, vector<int>& target) {
        long long res = 0;
        int n = nums.size();
        vector<int> differences(n, 0);
        for (int i = 0; i < n; ++i) {
            differences[i] = target[i] - nums[i];
        }
        int index = 0;
        while (index < n) {
            if (differences[index] < 0) {
                int start = index;
                while (index + 1 < n && differences[index + 1] < 0) index++;
                // [start, index]
                int current = 0;
                for (int j = start; j <= index; ++j) {
                    if (differences[j] < current) {
                        res += current - differences[j];
                    }
                    current = differences[j];
                }
            }
            else if (differences[index] > 0) {
                int start = index;
                while (index + 1 < n && differences[index + 1] > 0) index++;
                // [start, index]
                int current = 0;
                for (int j = start; j <= index; ++j) {
                    if (differences[j] > current) {
                        res += differences[j] - current;
                    }
                    current = differences[j];
                }
            }
            index++;
        }
        return res;
    }
};

