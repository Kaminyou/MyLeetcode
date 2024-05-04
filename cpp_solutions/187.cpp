class Solution {
public:
    int getEncodeBits(char c) {
        if (c == 'A') return 0b00;
        if (c == 'T') return 0b01;
        if (c == 'C') return 0b10;
        else return 0b11;
    }
    string encode2string(int encoded) {
        string res;
        for (int i = 0; i < 10; ++i) {
            int k = encoded & 0b11;
            if (k == 0b00) res.push_back('A');
            else if (k == 0b01) res.push_back('T');
            else if (k == 0b10) res.push_back('C');
            else res.push_back('G');
            encoded >>= 2;
        }
        reverse(res.begin(), res.end());
        return res;
    }
    vector<string> findRepeatedDnaSequences(string s) {
        vector<string> res;
        int n = s.size();
        if (n <= 10) return res;
        
        int encoded = 0;
        for (int i = 0; i < 9; ++i) {
            encoded <<= 2;
            encoded += getEncodeBits(s[i]);
        }
        
        unordered_map<int, int> mp;
        for (int i = 9; i < n; ++i) {
            encoded <<= 2;
            encoded += getEncodeBits(s[i]);
            mp[encoded]++;
            encoded -= getEncodeBits(s[i - 9]) << 18;
        }
        for (auto& element : mp) {
            if (element.second >= 2) {
                res.push_back(encode2string(element.first));
            }
        }
        return res;
    }
};