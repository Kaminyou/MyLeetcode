class StringIterator {
public:
    string compressedString;
    int currentPosition;
    int currentCount;
    char currentChar;
    int n;
    StringIterator(string compressedString) {
        this->compressedString = compressedString;
        currentPosition = 0;
        currentCount = 0;
        n = compressedString.size();
    }
    
    bool isDigit(char c) {
        return c >= '0' && c <= '9';
    }
    char next() {
        if (!hasNext()) return ' ';
        if (currentCount == 0) {
            currentChar = compressedString[currentPosition];
            currentPosition++;
            int start = currentPosition;
            while (currentPosition + 1 < n && isDigit(compressedString[currentPosition + 1])) {
                currentPosition++;
            }
            string temp = compressedString.substr(start, currentPosition - start + 1);
            currentCount = stoi(temp);
            currentPosition++;
        }
        currentCount--;
        return currentChar;
    }
    
    bool hasNext() {
        return !((currentCount == 0) && (currentPosition == n));
    }
};

/**
 * Your StringIterator object will be instantiated and called as such:
 * StringIterator* obj = new StringIterator(compressedString);
 * char param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */