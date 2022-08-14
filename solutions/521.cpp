class Solution {
public:
    int findLUSlength(string a, string b) {
        int aSize = a.size();
        int bSize = b.size();
        if (aSize != bSize) return max(aSize, bSize);
        else {
            if (a != b) return aSize;
            return -1;
        }
    }
};