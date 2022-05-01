class Solution {
public:
    string range2string(int start, int end, vector<int>& nums) {
        string out;
        for (int i = start; i <= end; i++) {
            out.push_back(nums[i] + '0');
        }
        return out;
    }
    int countDistinct(vector<int>& nums, int k, int p) {
        int left = 0;
        int right = 0;
        int count = 0;
        unordered_set<string> st;
        
        while (right < nums.size()) {
            if (nums[right] % p == 0) {
                count++;
            }
            while (count > k && left + 1 < nums.size()) {
                if (nums[left] % p == 0) count--;
                left++;
            }
            for (int start = left; start <= right; start++) {
                st.insert(range2string(start, right, nums));
            }
            
            right++;
        }
        return st.size();
    }
};