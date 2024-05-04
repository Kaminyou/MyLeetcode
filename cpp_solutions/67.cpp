class Solution {
public:
    string addBinary(string a, string b) {
        string out;
        reverse(a.begin(), a.end());
        reverse(b.begin(), b.end());
        int idxA = 0;
        int idxB = 0;
        int carry = 0;
        int current = 0;
        while (idxA < a.size() || idxB < b.size()) {
            current = carry;
            if (idxA < a.size()) {
                current += a[idxA] - '0';
                idxA++;
            }
            if (idxB < b.size()) {
                current += b[idxB] - '0';
                idxB++;
            }
            out.push_back(current % 2 + '0');
            carry = current / 2;
        }
        while  (carry) {
            out.push_back(carry % 2 + '0'); 
            carry /= 2;
        }
        reverse(out.begin(), out.end());
        return out;
    }
};