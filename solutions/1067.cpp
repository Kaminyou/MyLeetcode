class Solution {
public:
    int recursive(int d, int n) {
        if (n <= 9) {
            return (d == 0) ? 0 : (d <= n);
        }
        int res = 0;
        
        // e.g., 797
        // the last place -> 79_
        res += ((d == 0) ? (n / 10 - 1) : (n / 10));
        // to add 797
        //          ^
        if (n % 10 >= d) res++;
        res += recursive(d, n / 10) * 10;
        
        // to count 79x
        string temp = to_string(n / 10);
        
        // to delete 799 and 798 cases
        res -= count(temp.begin(), temp.end(), d + '0') * (9 - n % 10);
        return res;
    }
    int digitsCount(int d, int low, int high) {
        return recursive(d, high) - recursive(d, low - 1);
    }
};