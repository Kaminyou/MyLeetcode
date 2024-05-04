class Solution {
public:
    string removeDigit(string number, char digit) {
        vector<int> indices;
        int n = number.size();
        for (int i = 0; i < n; i++) {
            if (number[i] == digit) indices.push_back(i);
        }
        
        int index = -1;
        for (int i = 0; i < indices.size(); i++) {
            if (indices[i] + 1 < n && number[indices[i]] < number[indices[i] + 1]) {
                index = indices[i];
                break;
            }
        }
        
        if (index == -1) {
            index = indices[indices.size() - 1];
        }
        
        number.erase(index, 1);
        return number;
    }
};