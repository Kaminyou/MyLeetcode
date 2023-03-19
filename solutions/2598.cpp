class Solution {
public:
    int findSmallestInteger(vector<int>& nums, int value) {
        int n = nums.size();
        for (int i = 0; i < n; ++i) {
            int times = abs(nums[i] / value);
            if (nums[i] < 0) {
                nums[i] += (times + 1) * value;
            }
            nums[i] %= value;
        }
        unordered_set<int> st;
        unordered_map<int, int> mp;
        for (auto& num : nums) {
            int current = num;
            if (!st.count(current)) {
                st.insert(current);
                mp[current] = 0;
            }
            else {
                int times = mp[current];
                times++;
                if (current + times * value < INT_MAX - value) {
                    st.insert(current + times * value);
                    mp[current] = times;
                }
            }
        }
        for (int i = 0; i < nums.size() + 2; ++i) {
            if (!st.count(i)) return i;
        }
        return value + 1;
    }
};
