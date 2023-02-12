class Solution {
public:
    bool criteria(string& s, string& t, int window) {
        // should match t.size() - window
        int n = t.size() - window;
        if (n == 0) return true;
        vector<int> collection(n, -1);
        int index = 0;
        int collectionIdx = 0;
        int validCnt = 0;
        for (int i = 0; i < s.size(); ++i) {
            if (s[i] == t[index] && collectionIdx < collection.size()) {
                collection[collectionIdx] = i;
                collectionIdx++;
                validCnt++;
                index++;
            }
        }
        if (validCnt == n) return true;
        
        index = t.size() - 1;
        collectionIdx = n - 1;
        for (int i = s.size() - 1; i >= 0; --i) {
            if (s[i] == t[index] && collectionIdx >= 0) {
                
                if (collection[collectionIdx] == -1) {
                    validCnt++;
                }
                collection[collectionIdx] = i;
                if (validCnt == n) {
                    if (collectionIdx == 0) return true;
                    if (collectionIdx > 0 && i > collection[collectionIdx - 1]) return true;
                }
                index--;
                collectionIdx--;
            }
        }
        return false;
        
    }
    int minimumScore(string s, string t) {
        int left = 0;
        int right = t.size();
        
        while (left < right) {

            int mid = left + (right - left) / 2;
            if (criteria(s, t, mid)) right = mid;
            else left = mid + 1;
        }
        return left;
    }
};