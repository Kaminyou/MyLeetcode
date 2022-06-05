class TextEditor {
private:
    list<char> txt;
    list<char>::iterator cursor;
public:
    TextEditor() {
        cursor = txt.begin();
    }
    
    void addText(string text) {
        for (auto c : text) {
            cursor = txt.insert(cursor, c);
            cursor++;
        }
    }
    
    int deleteText(int k) {
        if (cursor == txt.begin()) {
            return 0;
        }
        cursor--;
        int count = 0;
        while (cursor != txt.begin() && k) {
            cursor = txt.erase(cursor);
            cursor--;
            count++;
            k--;
        }
        if (k) {
            cursor = txt.erase(cursor);
            count++;
            k--;
        }
        else{
            cursor++;
        }
        return count;
    }
    string _solve() {
        list<char>::iterator cursorTemp = cursor;
        int count = 10;
        int out = 0;
        while (cursorTemp != txt.begin() && count) {
            cursorTemp--;
            count--;
            out++;
        }
        string res = "";
        while (out) {
            out--;
            res.push_back(*cursorTemp);
            cursorTemp++;
        }
        return res;
    }
    string cursorLeft(int k) {
        while (cursor != txt.begin() && k) {
            cursor--;
            k--;
        }
        return _solve();
    }
    
    string cursorRight(int k) {
        while (cursor != txt.end() && k) {
            cursor++;
            k--;
        }
        return _solve();
    }
};

/**
 * Your TextEditor object will be instantiated and called as such:
 * TextEditor* obj = new TextEditor();
 * obj->addText(text);
 * int param_2 = obj->deleteText(k);
 * string param_3 = obj->cursorLeft(k);
 * string param_4 = obj->cursorRight(k);
 */