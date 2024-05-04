class TrieNode {
public:
    vector<TrieNode*> children;
    bool isEnd;
    TrieNode() {
        children.resize(62, nullptr);
        isEnd = false;
    }
};

class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        root = new TrieNode();
    }
    int char2idx(char c) {
        if (c >= '0' && c <= '9') return c - '0';
        if (c >= 'a' && c <= 'z') return c - 'a' + 10;
        return c - 'A' + 36;
    }
    void insert(string& s) {
        TrieNode* curr = root;
        for (auto c : s) {
            if (curr->children[char2idx(c)] == nullptr) {
                curr->children[char2idx(c)] = new TrieNode();
            }
            curr = curr->children[char2idx(c)];
        }
        curr->isEnd = true;
    }
    int search(string& s, int index) {
        TrieNode* curr = root;
        int maxMatch = -1;
        while (index < s.size()) {
            if (curr->children[char2idx(s[index])] == nullptr) {
                if (curr->isEnd) return index;
                return maxMatch;
            }
            else {
                curr = curr->children[char2idx(s[index])];
                index++;
                if (curr->isEnd) maxMatch = max(maxMatch, index);
            }
        }
        if (curr->isEnd) return index;
        return maxMatch;
    }
};
class Solution {
public:
    string addBoldTag(string s, vector<string>& words) {
        Trie* trie = new Trie();
        for (auto& word : words) trie->insert(word);
        int n = s.size();
        vector<bool> isBold(n, false);
        for (int i = 0; i < n; ++i) {
            int j = trie->search(s, i);
            if (j == -1) continue;
            for (int k = i; k < j; ++k) {
                isBold[k] = true;
            }
        }

        string res;
        int index = 0;
        while (index < n) {
            if (!isBold[index]) res.push_back(s[index]);
            else {
                int start = index;
                while (index + 1 < n && isBold[index + 1]) index++;
                res += "<b>";
                for (int k = start; k <= index; ++k) {
                    res.push_back(s[k]);
                }
                res += "</b>";
            }
            index++;
        }
        return res;
    }
};