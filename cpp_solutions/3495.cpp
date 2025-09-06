class Solution {
public:
    int count(int num) {
        int cnt = 0;
        while (num) {
            num /= 4;
            cnt++;
        }
        return cnt;
    }
    long long minOperations(vector<vector<int>>& queries) {
        long long res = 0;
        //[x,x,x,4^a -1], [4^a, ..., 4^b - 1], [4^b, ...]
        // a               a+1                  b+1
        for (auto& query : queries) {
            int start = query[0];
            int end = query[1];
            long long a = count(start);
            long long b = count(end) - 1;
            long long accum = 0;
            if (a > b) {
                accum = (end - start + 1) * a;
            }
            else {
                int aaaa = pow(4, a);
                accum += (aaaa - start) * a;
                int bbbb = pow(4, b);
                accum += ((long long)end - bbbb + 1) * (b + 1);
                for (int num = a + 1; num <= b; ++num) {
                    accum += (long long)num * (pow(4, num) - pow(4, num - 1));
                }
            }
            res += (accum - 1) / 2 + 1;
        }
        return res;
    }
};

