class Solution {
public:
    int maxLength(vector<string>& arr) {
        int n = arr.size();
        int res = 0;
        for (int state = 1; state < (1 << n); ++state) {
            vector<bool> hash(26, false); 
            bool valid = true;
            int length = 0;
            for (int i = 0; i < n && valid; ++i) {
                if ((state & (1 << i)) == (1 << i)) {
                    for (auto& c : arr[i]) {
                        if (hash[c - 'a']) {
                            valid = false;
                            break;
                        }
                        hash[c - 'a'] = true;
                        length++;
                    }
                }
                if (valid) res = max(res, length);
                else break;
            }
        }
        return res;
    }
};