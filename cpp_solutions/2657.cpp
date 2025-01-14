class Solution {
public:
    vector<int> findThePrefixCommonArray(vector<int>& A, vector<int>& B) {
        int n = A.size();
        vector<int> prefix(n, 0);
        vector<bool> hashA(n, false);
        vector<bool> hashB(n, false);
        int res = 0;
        for (int i = 0; i < n; ++i) {
            hashA[A[i]] = true;
            hashB[B[i]] = true;
            if (hashA[A[i]] && hashB[A[i]]) res++;
            if (A[i] != B[i] && hashA[B[i]] && hashB[B[i]]) res++;
            prefix[i] = res;
        }
        return prefix;
    }
};

