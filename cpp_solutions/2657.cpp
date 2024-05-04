class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> prefix(n, 0);
        vector<int> hashA(n, 0);
        vector<int> hashB(n, 0);
        for (int i = 0; i < n; ++i) {
            hashA[A[i] - 1]++;
            hashB[B[i] - 1]++;
            int count = 0;
            for (int j = 0; j < n; ++j) {
                count += min(hashA[j], hashB[j]);
            }
            prefix[i] = count;
        }
        return prefix;
    }
};