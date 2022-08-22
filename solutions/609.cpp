class Solution {
public:
    void seperate(string& source, string& filename, string& content) {
        int n = source.size();
        int i = 0;
        while (source[i] != '(') i++;
        filename = source.substr(0, i);
        content = source.substr(i + 1);
        content.pop_back();
    }
    vector<vector<string>> findDuplicate(vector<string>& paths) {
        unordered_map<string, vector<string>> content2paths;
        for (auto& path : paths) {
            string rt;
            string token;
            stringstream ss(path);
            int index = 0;
            while (getline(ss, token, ' ')) {
                if (index == 0) rt = token;
                else {
                    string filename;
                    string content;
                    seperate(token, filename, content);
                    content2paths[content].push_back(rt + "/" + filename);
                }
                index++;
            }
        }
        vector<vector<string>> res;
        for (auto& element : content2paths) {
            if (element.second.size() > 1) res.push_back(element.second);
        }
        return res;
    }
};