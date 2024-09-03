class Solution {
public:
    int getLucky(string s, int k) {
        int sum = 0;
        for (auto& c : s) {
            int temp = c - 'a' + 1;
            while (temp) {
                sum += temp % 10;
                temp /= 10;
            }
        }

        while (k > 1) {
            int temp = 0;
            while (sum) {
                temp += sum % 10;
                sum /= 10;
            }
            sum = temp;
            k--;
        }
        return sum;
    }
};
