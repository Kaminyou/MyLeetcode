class Solution {
public:
    int magicalString(int n) {
        string S = "122";
        int current = 2;
        while (S.size() < n) {
            char hint = S[current];
            if (hint == '1') {
                S.push_back('0' + ('3' - S.back()));
            }
            else {
                char temp = S.back();
                S.push_back('0' + ('3' - temp));
                S.push_back('0' + ('3' - temp));
            }
            current++;
        }
        int count = 0;
        for (int i = 0; i < n; ++i) {
            if (S[i] == '1') count++;
        }
        return count;
    }
};