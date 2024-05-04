class Solution {
public:
    string generate(string original, string plus, int state) {
        int index = 0;
        int sum = 0;
        while (state) {
            if (state & 1) {
                original.push_back(plus[index]);
                sum += (plus[index] - '0');
            }
            state >>= 1;
            index++;
        }
        if (sum % 3 == 0) {
            sort(original.begin(), original.end(), greater<char>());
            return original;
        }
        return "";
    }
    string largestMultipleOfThree(vector<int>& digits) {
        string original;
        unordered_map<int, int> cnt;
        for (auto& digit : digits) {
            if (digit == 0 || digit == 3 || digit == 6 || digit == 9) {
                original.push_back(digit + '0');
            }
            else {
                cnt[digit]++;
            }
        }
        for (auto& element : cnt) {
            auto [digit, count] = element;
            int remain = count % 3;
            if (count >= 3) remain += 3;
            int add = count - remain;
            for (int i = 0; i < add; ++i) original.push_back(digit + '0');
            element.second = remain;
        }
        string remainOne = "";
        string remainTwo = "";
        for (auto& element : cnt) {
            auto [digit, count] = element;
            if (digit % 3 == 1) {
                for (int i = 0; i < count; ++i) remainOne.push_back(digit + '0');
            }
            else {
                for (int i = 0; i < count; ++i) remainTwo.push_back(digit + '0');
            }
        }
        
        sort(remainOne.begin(), remainOne.end(), greater<char>());
        sort(remainTwo.begin(), remainTwo.end(), greater<char>());
        
        int m = remainOne.size();
        int n = remainTwo.size();
        //cout << m << " " << n << endl;
        string res = "";
        for (int i = 0; i <= m; ++i) {
            for (int j = 0; j <= n; ++j) {
                if ((i + j * 2) % 3 == 0) {
                    string temp = original;
                    temp += remainOne.substr(0, i);
                    temp += remainTwo.substr(0, j);
                    sort(temp.begin(), temp.end(), greater<char>());
                    if (temp.size() > res.size()) res = temp;
                    else if (temp.size() == res.size() && temp > res) res = temp;
                }
            }
        }
        if (res.size() > 1 && res[0] == '0') return "0";
        return res;
    }
};
// 9 -> V
// 8 -> 2 max 2
// 7 -> 1 max 2
// 6 -> V
// 5 -> 2 max 2
// 4 -> 1 max 2
// 3 -> V
// 2 -> 2 max 2
// 1 -> 1 max 2
// 0 -> V