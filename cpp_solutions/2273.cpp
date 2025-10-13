class Solution {
public:
    vector<string> removeAnagrams(vector<string>& words) {
        string currStr = "";
        vector<string> res;
        for (auto word : words) {
            string temp = word;
            sort(temp.begin(), temp.end());
            if (temp == currStr) continue;
            currStr = temp;
            res.push_back(word);
        }
        return res;
    }
};

class Solution {
public:
    int counts[26];
    bool isSame(string& a, string& b) {
        for (int i = 0; i < 26; ++i) counts[i] = 0;
        for (auto& c : a) counts[c - 'a']++;
        for (auto& c : b) counts[c - 'a']--;
        for (int i = 0; i < 26; ++i) {
            if (counts[i] != 0) return false;
        }
        return true;
    }
    vector<string> removeAnagrams(vector<string>& words) {
        int n = words.size();
        int index = 0;
        vector<string> res;
        while (index < n) {
            int left = index;
            while (index + 1 < n && isSame(words[index], words[index + 1])) index++;
            res.push_back(words[left]);
            index++;
        }
        return res;
    }
};
