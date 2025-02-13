class Solution {
public:
    bool valid(vector<int>& hash, int k) {
        for (auto& num : hash) {
            if (num >= k) return true;
        }
        return false;
    }
    int numberOfSubstrings(string s, int k) {
        int n = s.size();
        vector<int> hash(26, 0);
        int invalidNum = 0;
        int left = 0;
        for (int right = 0; right < n; ++right) {
            hash[s[right] - 'a']++;
            while (left < n && valid(hash, k)) {
                hash[s[left] - 'a']--;
                left++;
            }
            // [left, right], [left + 1, right] ... are invalid
            if (left <= right && !valid(hash, k)) {
                invalidNum += (right - left + 1);
            }
        }
        int res = 0;
        for (int i = 0; i < n; ++i) res += (i + 1);
        return res - invalidNum;
    }
};
