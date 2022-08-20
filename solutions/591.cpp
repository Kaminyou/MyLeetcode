class Solution {
public:
    bool isValidTag(string& tag) {
        if (tag.size() < 1 || tag.size() > 9) return false;
        for (auto c : tag) {
            if (c < 'A' || c > 'Z') return false;
        }
        return true;
    }
    bool isValid(string code) {
        int index = 0;
        bool hasTag = false;
        int n = code.size();
        stack<string> st;
        while (index < n) {
            if (index + 8 < n && code.substr(index, 9) == "<![CDATA[") {
                index += 9;
                while (index + 2 < n && code.substr(index, 3) != "]]>") {
                    index++;
                }
                if (index == n) return false;
                index += 3;
            }
            else if (index + 1 < n && code.substr(index, 2) == "</") {
                index += 2;
                int start = index;
                while (index < n && code[index] != '>') index++;
                if (index == n) return false;
                string tagName = code.substr(start, index - start);
                if (st.empty() || st.top() != tagName) return false;
                st.pop();
                index += 1;
                if (st.empty() && index != n) return false;
            }
            else if (code[index] == '<') {
                index += 1;
                int start = index;
                while (index < n && code[index] != '>') index++;
                if (index == n) return false;
                string tagName = code.substr(start, index - start);
                if (!hasTag && start != 1) return false;
                hasTag = true;
                if (!isValidTag(tagName)) return false;
                st.push(tagName);
                index++;
            }
            else index++;
        }
        if (!st.empty()) return false;
        if (!hasTag) return false;
        return true;
    }
};