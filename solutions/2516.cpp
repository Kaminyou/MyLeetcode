class Solution {
public:
    int takeCharacters(string s, int k) {
        int totalA = 0;
        int totalB = 0;
        int totalC = 0;
        for (auto& c : s) {
            if (c == 'a') totalA++;
            else if (c == 'b') totalB++;
            else totalC++;
        }
        if (totalA < k || totalB < k || totalC < k) return -1;
        int n = s.size();
        int left = 0;
        int cntA = 0;
        int cntB = 0;
        int cntC = 0;
        int window = 0;
        for (int right = 0; right < n; ++right) {
            if (s[right] == 'a') cntA++;
            else if (s[right] == 'b') cntB++;
            else cntC++;
            
            while (cntA > totalA - k || cntB > totalB - k || cntC > totalC - k) {
                if (s[left] == 'a') cntA--;
                else if (s[left] == 'b') cntB--;
                else cntC--;
                left++;
            }
            if (left <= right) {
                window = max(window, right - left + 1);
            }
        }
        return n - window;
    }
};
