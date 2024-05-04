class Solution {
public:
    int countSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        vector<int> transform(n, 0);
        
        int startIdx = -1;
        for (int i = 0; i < n; ++i) {
            if (nums[i] > k) transform[i] = 1;
            else if (nums[i] < k) transform[i] = -1;
            else {
                startIdx = i;
            }
        }
        
        vector<int> prefixSum(n + 1, 0);
        for (int i = 0; i < n; ++i) {
            prefixSum[i + 1] = prefixSum[i] + transform[i];
        }
        
        unordered_map<int, int> evenCnt;
        unordered_map<int, int> oddCnt;
        evenCnt[0]++;
        int cnt = 0;
        for (int i = 0; i < n; ++i) {
            if (i & 1) evenCnt[prefixSum[i + 1]]++;
            else oddCnt[prefixSum[i + 1]]++;
            
            if (i >= startIdx) {
                int target = prefixSum[i + 1];
                if (i & 1) {
                    cnt += evenCnt[target - 1];
                    cnt += oddCnt[target];
                }
                else {
                    cnt += evenCnt[target];
                    cnt += oddCnt[target - 1];
                }
            }
        }
        return cnt;
    }
};
