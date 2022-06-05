class Solution {
public:
    int partitionArray(vector<int>& nums, int k) {
        set<int> st;
        for (auto num : nums) st.insert(num);
        
        int res = 0;
        int start = -1;
        int end = -1;
        for (auto element : st) {
            if (start == -1) {
                start = element;
                end = start + k;
                res++;
                continue;
            }
            else {
                if (element > end) {
                    start = element;
                    end = start + k;
                    res++;
                }
            }
        }
        return res;
    }
};