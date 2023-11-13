class Solution {
public:
    int getIndex(char c) {
        if (c == 'A') return 0;
        if (c == 'E') return 1;
        if (c == 'I') return 2;
        if (c == 'O') return 3;
        if (c == 'U') return 4;
        if (c == 'a') return 5;
        if (c == 'e') return 6;
        if (c == 'i') return 7;
        if (c == 'o') return 8;
        if (c == 'u') return 9;
        return -1;
    }
    char mapIndex(int index) {
        if (index == 0) return 'A';
        if (index == 1) return 'E';
        if (index == 2) return 'I';
        if (index == 3) return 'O';
        if (index == 4) return 'U';
        if (index == 5) return 'a';
        if (index == 6) return 'e';
        if (index == 7) return 'i';
        if (index == 8) return 'o';
        if (index == 9) return 'u';
        return 'N';
    }
    string sortVowels(string s) {
        vector<int> counts(10, 0);
        for (auto& c : s) {
            int index = getIndex(c);
            if (index != -1) counts[index]++;
        }
        int n = s.size();
        int current = 0;
        for (int i = 0; i < n; ++i) {
            int index = getIndex(s[i]);
            if (index != -1) {
                while (counts[current] == 0) current++;
                s[i] = mapIndex(current);
                counts[current] -= 1;
            }
        }
        return s;
    }
};
