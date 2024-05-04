class Solution {
public:
    pair<int, int> toComplex(string& s) {
        int a = 0;
        int b = 0;
        int index = 0;
        stringstream ss(s);
        string token;
        while (getline(ss, token, '+')) {
            if (index == 0) a = stoi(token);
            else b = stoi(token.substr(0, token.size() - 1));
            index++;
        }
        return make_pair(a, b);
    }
    string complexNumberMultiply(string num1, string num2) {
        auto [num1A, num1B] = toComplex(num1);
        auto [num2A, num2B] = toComplex(num2);
        int real = num1A * num2A - num1B * num2B;
        int imaginary = num1B * num2A + num1A * num2B;
        return to_string(real) + "+" + to_string(imaginary) + "i";
    }
};