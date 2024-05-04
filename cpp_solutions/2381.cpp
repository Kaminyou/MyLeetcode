class Solution {
public:
    string shiftingLetters(string s, vector<vector<int>>& shifts) {
        int n = s.size();
        vector<int> diff(n + 1, 0);
        for (auto& shift : shifts) {
            int start = shift[0];
            int end = shift[1];
            int move = (shift[2] == 0) ? -1 : 1;
            diff[start] += move;
            diff[end + 1] -= move;
        }
        
        int currMove = 0;
        string res;
        for (int i = 0; i < n; ++i) {
            currMove += diff[i];
            int c = s[i] - 'a';
            c += currMove + 52;
            c %= 26;
            c += 52;
            c %= 26;
            //cout << c << endl;
            res.push_back(c + 'a');
        }
        return res;
    }
};