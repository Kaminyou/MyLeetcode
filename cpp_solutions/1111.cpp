class Solution {
public:
    vector<int> maxDepthAfterSplit(string seq) {
        int n = seq.size();
        vector<int> res(n, 0);
        int depth = 0;
        for (int i = 0; i < n; ++i) {
            if (seq[i] == '(') {
                depth++;
                if (depth & 1) res[i] = 1;
            }
            else {
                if (depth & 1) res[i] = 1;
                depth--;
            }
        }
        return res;
    }
};
