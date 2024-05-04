class Solution {
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        unordered_set<string> st;
        bool flag = false;
        for (auto& word : wordList) {
            st.insert(word);
            if (word == endWord) flag = true;
        }
        if (!flag) return 0;
        
        queue<pair<string, int>> q;
        q.push(make_pair(beginWord, 1));
        while (!q.empty()) {
            auto [node, path] = q.front();
            q.pop();
            for (int i = 0; i < node.size(); i++) {
                char original = node[i];
                for (char j = 'a'; j <= 'z'; ++j) {
                    if (j == original) continue;
                    node[i] = j;
                    if (node == endWord) return path + 1;
                    if (st.find(node) != st.end()) {
                        q.push(make_pair(node, path + 1));
                        st.erase(node);
                    }
                }
                node[i] = original;
            }
        }
        return 0;
    }
};