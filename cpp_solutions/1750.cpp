class Solution {
public:
    int minimumLength(string s) {
        int left = 0;
        int right = s.size() - 1;
        while (left < right && s[left] == s[right]) {            
            int length = right - left + 1;
            while (left + 1 < right && s[left] == s[left + 1]) left++;
            while (right - 1 > left && s[right] == s[right - 1]) right--;
            left++;
            right--;
        }
        return right - left + 1;
    }
};
