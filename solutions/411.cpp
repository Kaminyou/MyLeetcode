class Solution {
public:
    pair<int, int> countState(int state, int n) {
        vector<bool> bits(n, false);
        for (int i = 0; i < n; ++i) {
            if (state & 1) bits[i] = true;
            state >>= 1;
        }
        int negative = 0;
        int positive = 0;
        int index = 0;
        while (index < n) {
            if (bits[index] == 0) {
                while (index + 1 < n && bits[index + 1] == 0) index++;
                negative++;
            }
            else positive++;
            index++;
        }
        return make_pair(negative, positive);
    }
    string toAbbrev(string& target, int state, int n) {
        vector<bool> bits(n, false);
        for (int i = 0; i < n; ++i) {
            if (state & 1) bits[i] = true;
            state >>= 1;
        }
        int negative = 0;
        int positive = 0;
        int index = 0;
        string res = "";
        while (index < n) {
            if (bits[index] == 0) {
                int count = 1;
                while (index + 1 < n && bits[index + 1] == 0) {
                    index++;
                    count++;
                }
                res += (to_string(count));
            }
            else res.push_back(target[index]);
            index++;
        }
        return res;
    }
    void printState(int state, int n) {
        for (int i = 0; i < n; ++i) {
            if (state & 1) cout << "1";
            else cout << "0";
            state >>= 1;
        }
        cout << endl;
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
            auto [neg, pos] = countState(state, n);
            
            if (neg + pos < abbrevCount) {
                res = toAbbrev(target, state, n);
                abbrevCount = neg + pos;
            }
        }
        return res;
    }
};