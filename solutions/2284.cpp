class Solution {
public:
    int countWord(string& message) {
        stringstream ss(message);
        string token;
        int count = 0;
        while (getline(ss, token, ' ')) {
            count++;
        }
        return count;
    }
    string largestWordCount(vector<string>& messages, vector<string>& senders) {
        unordered_map<string, int> mp;
        for (int i = 0; i < messages.size(); ++i) {
            mp[senders[i]] += countWord(messages[i]);
        }
        int maxVal = INT_MIN;
        string ans = "";
        for (auto element : mp) {
            if (element.second > maxVal) {
                ans = element.first;
                maxVal = element.second;
            }
            else if (element.second == maxVal) {
                if (element.first > ans) ans = element.first;
            }
        }
        return ans;
    }
};