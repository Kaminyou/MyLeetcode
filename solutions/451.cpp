class Solution {
public:
    static bool compare(const pair<int, int>& p1, const pair<int, int>& p2) {
        return p1.second > p2.second;
    }
    string frequencySort(string s) {
        vector<pair<int, int>> counts;
        for (int i = 0; i < 256; ++i) counts.push_back(make_pair(i, 0));
        for (auto c : s) {
            counts[c].second++;
        }
        sort(counts.begin(), counts.end(), compare);
        string res;
        for (int i = 0; i < 256; ++i) {
            if (counts[i].second == 0) continue;
            char c = counts[i].first;
            int count = counts[i].second;
            res += string(count, c);
        }
        return res;
    }
};

class Solution {
public:
    int char2idx(char c) {
        if (c >= 'a' && c <= 'z') return c - 'a';
        if (c >= 'A' && c <= 'Z') return c - 'A' + 26;
        return c - '0' + 52;
    }
    static bool compare(pair<int, char>& p1, pair<int, char>& p2) {
        return p1.first > p2.first;
    }
    string frequencySort(string s) {
        vector<pair<int, char>> counts;
        for (int i = 0; i < 26; ++i) {
            counts.push_back({0, i + 'a'});
        }
        for (int i = 0; i < 26; ++i) {
            counts.push_back({0, i + 'A'});
        }
        for (int i = 0; i < 10; ++i) {
            counts.push_back({0, i + '0'});
        }
        for (auto& c : s) {
            counts[char2idx(c)].first++;
        }
        sort(counts.begin(), counts.end(), compare);
        string res;
        for (int i = 0; i < 62; ++i) {
            res += string(counts[i].first, counts[i].second);
        }
        return res;
    }
};