class Solution {
public:
    void processing(string s, int num, unordered_map<string, int>& counts) {
        counts[s] += num;
        if (s.find('.') == string::npos) return;
        int index = s.find('.');
        string nextStr = s.substr(index + 1);
        processing(nextStr, num, counts);
    }
    vector<string> subdomainVisits(vector<string>& cpdomains) {
        unordered_map<string, int> counts;
        for (auto& cpdomain : cpdomains) {
            stringstream ss(cpdomain);
            string token;
            
            string domain;
            int count;
            int index = 0;
            while (getline(ss, token, ' ')) {
                if (index == 0) count = stoi(token);
                else domain = token;
                index++;
            }
            processing(domain, count, counts);
        }
        
        vector<string> res;
        for (auto& element : counts) {
            res.push_back(to_string(element.second) + " " + element.first);
        }
        return res;
    }
};