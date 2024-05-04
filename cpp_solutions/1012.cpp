class Solution {
public:
    int permutation(int m, int n) {
        // m number with len n
        // m * (m - 1) * (m - 2) .. * (m - n + 1) 
        int res = 1;
        while (n) {
            res *= m;
            m--;
            n--;
        }
        return res;
    }
    int numDupDigitsAtMostN(int n) {
        vector<int> digits; // to store each digit
        for (int x = n + 1; x > 0; x /= 10) {
            digits.push_back(x % 10);
        }
        // make it from high to low
        // e.g., n=137 => [7, 1, 3] => [1, 3, 7]
        reverse(digits.begin(), digits.end());
        
        // get the # of digits
        int size = digits.size();
        
        // to count the number without duplicates
        int res = 0;
        
        // one digit to (size - 1) digits
        // e.g, n=8759 (4 digits), ignore leading 8 here
        // so the last 3 digits have 9 * (9 * 8) permutations
        // the last 2 digits have 9 * (9) permutations
        // the last 1 digits have 9 permutations
        for (int i = 1; i < size; i++) {
            res += 9 * permutation(9, i - 1);
        }
        
        // consider the leading digit
        unordered_set<int> st; // to store the leading fixed one
        // for each digit
        for (int i = 0; i < size; i++) {
            // i = 0 (first digit) e.g., n=8759 | the free will be
            // 1xxx, 2xxx, ..., 7xxx
            // i > 0 e.g., n=8759 | the free will be
            // 80xx, 81xx, ...86xx
            for (int j = i > 0 ? 0 : 1; j < digits[i];j++) {
                // the current digit should not duplicated with the fixed one
                if (st.find(j) != st.end()) continue;
                res += permutation(9 - i, size - i - 1);
            }
            // if the current leading digit duplicate with previous ones => break
            if (st.find(digits[i]) != st.end()) break;
            // insert the current leading digit to the hash table
            st.insert(digits[i]);
        }
        return n - res;
    }
};