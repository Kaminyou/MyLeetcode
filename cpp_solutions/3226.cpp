class Solution {
public:
    vector<int> toBits(int num) {
        vector<int> res(32, 0);
        int index = 0;
        while (num) {
            if (num & 1) res[index] = 1;
            num >>= 1;
            index++;
        }
        return res;
    }
    int minChanges(int n, int k) {
        vector<int> v1 = toBits(n);
        vector<int> v2 = toBits(k);
        int res = 0;
        for (int i = 0; i < 32; ++i) {
            if (v1[i] == 1 && v2[i] == 0) res++;
            if (v1[i] == 0 && v2[i] == 1) return -1;
        }
        return res;
    }
};
