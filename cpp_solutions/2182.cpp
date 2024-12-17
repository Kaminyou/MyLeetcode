class Solution {
public:
    string repeatLimitedString(string s, int repeatLimit) {
        vector<int> charHash(26, 0);
        
        for (char c : s) {
            charHash[c - 'a']++;
        }
        
        int top = -1;
        int second = -1;
        queue<int> available;
        for (int i = 25; i >= 0; i--) {
            if (charHash[i] > 0) available.push(i);
        }
        top = available.front();
        available.pop();
        if (!available.empty()) {
            second = available.front();
            available.pop();
        }
        
        string out = "";
        while (top >= 0) {
            int maxRepeat = min(charHash[top], repeatLimit);
            for (int i = 0; i < maxRepeat; i++) {
                out += top + 'a';
                charHash[top]--;
            }
            if (charHash[top] > 0 && second >= 0) {
                out += second + 'a';
                charHash[second]--;
                if (charHash[second] == 0) {
                    second = -1;
                    if (!available.empty()) {
                        second = available.front();
                        available.pop();
                    }
                }
            }
            else if (charHash[top] > 0 && second == -1) {
                break;
            }
            else {
                top = second;
                second = -1;
                if (!available.empty()) {
                    second = available.front();
                    available.pop();
                }
            }
            
        }
        
        return out;
    }
};

