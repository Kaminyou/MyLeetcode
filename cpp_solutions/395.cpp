class Solution {
public:
    int longestSubstring(string s, int k) {
        int res = 0;
        int n = s.size();
        
        // allow count in s
        for (int count = 1; count <= 26; ++count) {
            int left = 0;
            int right = 0;
            vector<int> counter(26, 0);
            int unique = 0;
            
            while (right < n) {
                bool flag = true;
                int index = s[right] - 'a';
                if (counter[index] == 0) unique++;
                counter[index]++;
                
                while (unique > count) {
                    int indexLeft = s[left] - 'a';
                    if (counter[indexLeft] == 1) unique--;
                    counter[indexLeft]--;
                    left++;
                }
                
                for (int i = 0; i < 26; ++i) {
                    if (counter[i] > 0 && counter[i] < k) {
                        flag = false;
                        break;
                    }
                }
                if (flag) res = max(res, right - left + 1);
                right++;
            }
        }
        return res;
    }
};