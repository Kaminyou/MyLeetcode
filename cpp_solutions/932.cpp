class Solution {
public:
    vector<int> beautifulArray(int n) {
        if (n == 1) return {1};
        vector<int> even = beautifulArray(n / 2);
        vector<int> odd = beautifulArray(n - n / 2);
        vector<int> ans;
        for (auto& element : even) {
            ans.push_back(element * 2);
        }
        for (auto& element : odd) {
            ans.push_back(element * 2 - 1);
        }
        return ans;
    }
};