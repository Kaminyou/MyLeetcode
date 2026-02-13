class Solution {
public:
    long long counts32key(int* counts) {
        long long a = counts[0] - counts[1] + 1e5;
        long long b = counts[1] - counts[2] + 1e5;
        return (a << 20) + b;
    }
    long long counts22key(int* counts) {
        long long a = counts[0] - counts[1] + 1e5;
        return a;
    }
    int caseOne(string& s) {
        int res = 0;
        int n = s.size();
        char c = 'z';
        int count = 0;
        for (int index = 0; index < n; ++index) {
            if (c != s[index]) {
                c = s[index];
                count = 1;
            }
            else count++;
            res = max(res, count);
        }
        return res;
    }
    int caseTwo(string& s, char a, char b, char c) {
        int n = s.size();
        unordered_map<long long, int> mp;
        int counts[2] = {0, 0};
        int res = 0;
        mp[counts22key(counts)] = -1;
        for (int i = 0; i < n; ++i) {
            if (s[i] == c) {
                mp.clear();
                counts[0] = 0;
                counts[1] = 0;
                mp[counts22key(counts)] = i;
            }
            else {
                if (s[i] == a) counts[0]++;
                else counts[1]++;

                long long key = counts22key(counts);
                if (mp.count(key)) {
                    res = max(res, i - mp[key]);
                }
                else {
                    mp[key] = i;
                }
            }
        }
        return res;
    }
    int caseThree(string& s) {
        int n = s.size();
        unordered_map<long long, int> mp;
        int counts[3] = {0, 0, 0};
        int res = 0;
        mp[counts32key(counts)] = -1;
        for (int i = 0; i < n; ++i) {
            counts[s[i] - 'a']++;
            long long key = counts32key(counts);
            if (mp.count(key)) {
                res = max(res, i - mp[key]);
            }
            else {
                mp[key] = i;
            }
        }
        return res;
    }
    int longestBalanced(string s) {
        int res = 0;
        res = max(res, caseOne(s));
        res = max(res, caseTwo(s, 'a', 'b', 'c'));
        res = max(res, caseTwo(s, 'a', 'c', 'b'));
        res = max(res, caseTwo(s, 'b', 'c', 'a'));
        res = max(res, caseThree(s));
        return res;
    }
};
