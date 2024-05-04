class Solution {
public:
    void change(char& c) {
        if (c >= 'A' && c <= 'Z') {
            int diff = c - 'A';
            c = diff + 'a';
        }
        return;
    }
    string toLowerCase(string s) {
        for (auto& c : s) change(c);
        return s;
    }
};