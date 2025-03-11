class Solution {
public:
    bool isValid(vector<int>& counts) {
        for (auto& count : counts) {
            if (count < 1) return false;
        }
        return true;
    }
    int numberOfSubstrings(string s) {
        vector<int> counts(3, 0);
        int right = 0;
        int n = s.size();
        int res = 0;
        for (int left = 0; left < n; ++left) {
            while (right < n && !isValid(counts)) {
                counts[s[right] - 'a']++;
                right++;
            }
            if (isValid(counts)) res += (n - right + 1);
            counts[s[left] - 'a']--;
        }
        return res;
    }
};
