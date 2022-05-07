class Solution {
public:
    int binarySearch(vector<int>& arr, int x) {
        int left = 0;
        int right = arr.size();
        while (left < right) {
            int mid = left + (right - left) / 2;
            // >=: should replace the same one
            if (arr[mid] >= x) right = mid; 
            else left = mid + 1;
        }
        return left;
    }
    int lengthOfLIS(vector<int>& nums) {
        vector<int> ans;
        for (auto num : nums) {
            int idx = binarySearch(ans, num);
            if (idx == ans.size()) ans.push_back(num);
            else ans[idx] = num;
        }
        return ans.size();
    }
};