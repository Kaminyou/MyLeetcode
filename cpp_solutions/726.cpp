class Solution {
public:
    
    bool isUpper(char c){
        return 'A' <= c && c <= 'Z';
    }
    
    bool isLower(char c){
        return 'a' <= c && c <= 'z';
    }
    
    bool isDigit(char c){
        return '0' <= c && c <= '9';
    }
    
    bool isLetter(char c){
        return isUpper(c) || isLower(c);
    }
    
    int char2digit(char c){
        return c - '0';
    }
    
    int string2num(string s){
        if (s == "") return 1;
        return stoi(s);
    }
    
    unordered_map<string, int> chemicals;
    
    void parse(string& formula, int& pos, int factor){
        string number = "";
        string chemical = "";
        
        while (pos >= 0){
            char c = formula[pos];
            pos--;
            
            if (isDigit(c)){
                number = c + number;
            }
            else if (isLetter(c)){
                chemical = c + chemical;
                if (isUpper(c)){
                    chemicals[chemical] += string2num(number) * factor;
                    number = "";
                    chemical = "";
                }
            }
            else if (c == ')'){
                parse(formula, pos, factor * string2num(number));
                number = "";
            }
            else if (c == '('){
                break;
            }
        }
    }
    
    string countOfAtoms(string formula) {
        int size = formula.size() - 1;
        parse(formula, size, 1);
        
        vector<string> chemical_names;
        // sort by chemical
        for (auto ch : chemicals) {
            chemical_names.push_back(ch.first);
        }
        
        sort(chemical_names.begin(), chemical_names.end());
        
        string out;
        for (string chemical_name : chemical_names){
            out += chemical_name;
            out += (chemicals[chemical_name] > 1) ? to_string(chemicals[chemical_name]) : "";
        }
        return out;   
    }
};

