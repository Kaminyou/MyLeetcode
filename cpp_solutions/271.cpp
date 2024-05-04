class Codec {
public:
    const int chunk = 3;
    string toPrefix(const string& s) {
        int n = s.size();
        string out = to_string(n);
        int size = out.size();
        return string(chunk - size, '0') + out;
    }
    // Encodes a list of strings to a single string.
    string encode(vector<string>& strs) {
        string res;
        for (auto str : strs) {
            string temp = toPrefix(str);
            res += temp;
            res += str;
        }
        return res;
    }

    // Decodes a single string to a list of strings.
    vector<string> decode(string s) {
        vector<string> res;
        int index = 0;
        while (index < s.size()) {
            int size = stoi(s.substr(index, chunk));
            index += chunk;
            string temp = s.substr(index, size);
            res.push_back(temp);
            index += size;
        }
        return res;
    }
};

// Your Codec object will be instantiated and called as such:
// Codec codec;
// codec.decode(codec.encode(strs));