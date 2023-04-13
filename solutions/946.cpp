class Solution {
public:
    bool validateStackSequences(vector<int>& pushed, vector<int>& popped) {
        int indexPush = 0;
        int indexPop = 0;
        int n = popped.size();
        stack<int> st;
        while (indexPop < n) {
            if (!st.empty() && st.top() == popped[indexPop]) {
                st.pop();
                indexPop++;
            }
            else if (indexPush == n) return false;
            else {
                st.push(pushed[indexPush]);
                indexPush++;
            }
        }
        return st.empty();
    }
};