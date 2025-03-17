class Solution {
public:
    bool divideArray(vector<int>& nums) {
        vector<int> hash(501, 0);
        for (auto& num : nums) hash[num]++;
        for (int i = 0; i <= 500; ++i) {
            if (hash[i] & 1) return false;
        }
        return true;
    }
};
