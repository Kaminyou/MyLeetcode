class Solution {
public:
    deque<unordered_map<string, int>> scopes_;
    string getToken(string& expression, int& pos) {
        string token;
        while (pos < expression.size() && expression[pos] != ')' && expression[pos] != ' ') {
            token.push_back(expression[pos]);
            pos++;
        }
        return token;
    }
    int getValue(string& token) {
        for (auto& scope : scopes_) {
            if (scope.find(token) != scope.end()) return scope[token];
        }
        return 0;
    }
    int eval(string& expression, int& pos) {
        scopes_.push_front(unordered_map<string, int>());
        int value = 0;
        if (expression[pos] == '(') pos++;
        string token = getToken(expression, pos);
        
        if (token == "add") {
            pos++;
            int v1 = eval(expression, pos);
            pos++;
            int v2 = eval(expression, pos);
            value = v1 + v2;
        }
        else if (token == "mult") {
            pos++;
            int v1 = eval(expression, pos);
            pos++;
            int v2 = eval(expression, pos);
            value = v1 * v2;
        }
        else if (token == "let") {
            string var;
            while (expression[pos] != ')') {
                pos++;
                if (expression[pos] == '(') {
                    pos++;
                    value = eval(expression, pos);
                    break;
                }
                var = getToken(expression, pos);
                if (expression[pos] == ')') {
                    if (isalpha(var[0])) {
                        value = getValue(var);
                    }
                    else {
                        value = stoi(var);
                    }
                    break;
                }
                pos++;
                value = scopes_.front()[var] = eval(expression, pos);
            }
        }
        else if (isalpha(token[0])) {
            value = getValue(token);
        }
        else {
            value = stoi(token);
        }
        if (expression[pos] == ')') pos++;
        scopes_.pop_front();
        return value;
    }
    int evaluate(string expression) {
        scopes_.clear();
        int position = 0;
        return eval(expression, position);
    }
};