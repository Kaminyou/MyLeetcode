class Solution {
public:
    vector<int> parser(string& log) {
        stringstream ss(log);
        string token;
        vector<string> information;
        while(getline(ss, token, ':')) {
            information.push_back(token);
        }
        int func = stoi(information[0]);
        int isStart = 1;
        if (information[1][0] == 'e') isStart = 0;
        int time = stoi(information[2]);
        return {func, isStart, time};
    }
    vector<int> exclusiveTime(int n, vector<string>& logs) {
        stack<int> st;
        int currentTime = 0;
        vector<int> res(n, 0);
        for (auto& log : logs) {
            vector<int> info = parser(log);
            if (info[1]) {
                if (!st.empty()) {
                    int prevFunc = st.top();
                    res[prevFunc] += info[2] - currentTime;
                }
                currentTime = info[2];
                st.push(info[0]);
            }
            else {
                int currFunc = st.top();
                st.pop();
                res[currFunc] += info[2] - currentTime + 1;
                currentTime = info[2] + 1;
            }
        }
        return res;
    }
};