class Solution {
public:
    string emailParser(string& email) {
        string out;
        int index = 0;
        int n = email.size();
        bool beforeAt = true;
        while (index < n) {
            if (email[index] == '.') {
                if (!beforeAt) out.push_back(email[index]);
            }
            else if (email[index] == '+' && beforeAt) {
                while (index + 1 < n && email[index + 1] != '@') index++;
            }
            else if (email[index] == '@') {
                beforeAt = false;
                out.push_back(email[index]);
            }
            else {
                out.push_back(email[index]);
            }
            index++;
        }
        return out;
    }
    int numUniqueEmails(vector<string>& emails) {
        unordered_set<string> st;
        for (auto email : emails) {
            string refined = emailParser(email);
            st.insert(refined);
        }
        return st.size();
    }
};