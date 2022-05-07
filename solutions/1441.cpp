class Solution {
public:
    vector<string> buildArray(vector<int>& target, int n) {
        int index = 0;
        vector<string> res;
        for (int i = 1; i <= n; i++) {
            if (i == target[index]) {
                res.push_back("Push");
                index++;
                if (index == target.size()) break;
            }
            else {
                res.push_back("Push");
                res.push_back("Pop");
            }
        }
        return res;
    }
};