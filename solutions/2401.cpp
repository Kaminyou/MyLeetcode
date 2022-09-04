class Solution {
public:
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        int left = 0;
        int res = 0;
        int current = 0;
        
        for (int right = 0; right < n; ++right) {
            while ((current & nums[right]) > 0) {
                current ^= nums[left];
                left++;
            }
            current ^= nums[right];
            res = max(res, right - left + 1);
        }
        return res;
    }
};

class Solution {
public:
    vector<bool> toBinary(int num) {
        vector<bool> binary(32, false);
        int index = 0;
        while (num) {
            if (num & 1) binary[index] = true;
            num /= 2;
            index++;
        }
        return binary;
    }
    int longestNiceSubarray(vector<int>& nums) {
        int n = nums.size();
        vector<bool> hash(32, false);
        int count = 0;
        int res = 0;
        vector<vector<bool>> memo(n);
        for (int i = 0; i < n; ++i) {
            memo[i] = toBinary(nums[i]);
        }
        for (int i = 0; i < n; ++i) {
            for (int j = 0; j < 32; ++j) hash[j] = false;
            count = 0;
            
            for (int k = 0; k <= 32; ++k) {
                if (i + k >= n) break;
                bool flag = true;
                for (int j = 0; j < 32; ++j) {
                    if (memo[i + k][j] && hash[j]) {
                        flag = false;
                        break;
                    }
                    if (memo[i + k][j]) hash[j] = memo[i + k][j];
                }

                if (flag) {
                    count++;
                    res = max(res, count);
                }
                else {
                    break;
                }
            }
        }
        return res;
    }
};