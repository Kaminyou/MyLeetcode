class Solution {
public:
    char kthCharacter(long long k, vector<int>& operations) {
        int ops = 0;
        while (k > 1) {
            long long now = 1;
            int index = 0;
            while ((now << 1) < k) {
                now <<= 1;
                index++;
            }
            ops += operations[index];
            k -= now;
        }
        return (ops % 26) + 'a';
    }
};

