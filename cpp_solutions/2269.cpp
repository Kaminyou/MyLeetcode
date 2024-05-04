class Solution {
public:
    int divisorSubstrings(int num, int k) {
        string numStr = to_string(num);
        int n = numStr.size();
        int res = 0;
        for (int i = 0; i < n - k + 1; i++) {
            string sub = numStr.substr(i, k);
            int subInt = stoi(sub);
            if (subInt == 0) continue;
            if (num % subInt == 0) res++;
        }
        return res;
    }
};