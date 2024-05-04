class Solution {
public:
    vector<bool> toBinary(int num) {
        vector<bool> v(32, 0);
        int index = 0;
        while (num) {
            if (num & 1) v[index] = true;
            else v[index] = false;
            index++;
            num >>= 1;
        }
        return v;
    }
    bool isValid(vector<bool>& target, vector<int>& counting) {
        for (int i = 0; i < 32; ++i) {
            if (target[i]) {
                if (counting[i] <= 0) return false;
            }
        }
        return true;
    }
    vector<int> smallestSubarrays(vector<int>& nums) {
        vector<vector<bool>> numsBinary;
        for (auto& num : nums) numsBinary.push_back(toBinary(num));
        vector<bool> target(32, false);
        vector<int> counting(32, 0);
        int n = nums.size();
        vector<int> res(n, -1);
        int right = n - 1;
        
        for (int left = n - 1; left >= 0; --left) {
            for (int i = 0; i < 32; ++i) {
                target[i] = target[i] | numsBinary[left][i];
                counting[i] += numsBinary[left][i];
            }
            
            while (isValid(target, counting) && right >= 0 && right >= left) {
                for (int i = 0; i < 32; ++i) {
                    counting[i] -= numsBinary[right][i];
                }
                right--;
            }
            
            res[left] = (right + 1) - left + 1;
        }
        return res;
    }
};