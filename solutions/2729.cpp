class Solution {
public:
    bool isFascinating(int n) {
        string res = to_string(n) + to_string(n * 2) + to_string(n * 3);
        vector<int> hash(10, 0);
        for (auto c : res) {
            hash[c - '0'] += 1;
        }
        if (hash[0] >= 1) return false;
        for (int i = 1; i < 10; ++i) {
            if (hash[i] != 1) return false;
        }
        return true;
    }
};