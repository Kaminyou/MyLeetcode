class Solution {
public:
    vector<string> mapping = {".-","-...","-.-.","-..",".","..-.","--.","....","..",".---","-.-",".-..","--","-.","---",".--.","--.-",".-.","...","-","..-","...-",".--","-..-","-.--","--.."};
    string concat(string& s) {
        string res;
        for (auto c : s) {
            res += mapping[c - 'a'];
        }
        return res;
    }
    int uniqueMorseRepresentations(vector<string>& words) {
        unordered_set<string> st;
        for (auto& word : words) st.insert(concat(word));
        return st.size();
    }
};