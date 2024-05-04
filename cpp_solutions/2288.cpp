class Solution {
public:
    string discountPrices(string sentence, int discount) {
        istringstream iss(sentence);
        ostringstream oss;
        string token;
        while (iss >> token) {
            if (token[0] != '$') {
                oss << token << " ";
                continue;
            }
            bool sign = false;
            for (int i = 1; i < token.size(); ++i) {
                char c = token[i];
                if (c > '9' || c < '0') {
                    sign = true;
                    break;
                }
            }
            if (sign || token.size() == 1) {
                oss << token << " ";
                continue;
            }
            long long price = stoll(token.substr(1));
            double pricePrecise = price * 0.01 * (100 - discount);
            oss << "$" << fixed << setprecision(2) << pricePrecise << " ";
        }
        string ans = oss.str();
        ans.pop_back();
        return ans;
    }
};