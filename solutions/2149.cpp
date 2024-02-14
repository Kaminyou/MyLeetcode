class Solution {
public:
    vector<int> rearrangeArray(vector<int>& nums) {
        int n = nums.size();
        vector<int> res(n, 0);
        int posIdx = 0;
        int negIdx = 1;
        for (auto& num : nums) {
            if (num > 0) {
                res[posIdx] = num;
                posIdx += 2;
            }
            else {
                res[negIdx] = num;
                negIdx += 2;
            }
        }
        return res;
    }
};
