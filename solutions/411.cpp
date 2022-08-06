class Solution {
public:
    int countState(int state, int n) {
        int negative = 0;
        int positive = 0;
        while (n) {
            if (state & 1) {
                positive++;
                state >>= 1;
                n--;
            }
            else {
                state >>= 1;
                n--;
                negative++;
                while (n && (state & 1) == 0) {
                    state >>= 1;
                    n--;
                }
            }
        }
        return negative + positive;
    }
    string toAbbrev(string& target, int state, int n) {
        string res;
        int size = n;
        while (n) {
            if (state & 1) {
                res.push_back(target[size - n]);
                state >>= 1;
                n--;
            }
            else {
                state >>= 1;
                n--;
                int count = 1;
                while (n && (state & 1) == 0) {
                    state >>= 1;
                    n--;
                    count++;
                }
                res += to_string(count);
            }
        }
        return res;
    }
    string minAbbreviation(string target, vector<string>& dictionary) {
        unordered_set<int> dictionaryHash;
        int n = target.size();
        for (auto& word : dictionary) {
            if (word.size() != n) continue;
            else {
                int state = 0;
                for (int i = 0; i < n; ++i) {
                    if (target[i] == word[i]) state |= (1 << i);
                }
                for (int subset = state; subset; subset = (subset - 1) & state) {
                    dictionaryHash.insert(subset);
                }
                dictionaryHash.insert(0);
            }
        }
        int abbrevCount = n;
        string res = target;
        for (int state = 0; state < (1 << n); ++state) {
            if (dictionaryHash.find(state) != dictionaryHash.end()) continue;
            int currCount = countState(state, n);
            if (currCount < abbrevCount) {
                res = toAbbrev(target, state, n);
                abbrevCount = currCount;
            }
        }
        return res;
    }
};