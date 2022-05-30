class Vector2D {
private:
    vector<vector<int>>::iterator x, y;
    vector<int>::iterator z;
public:
    Vector2D(vector<vector<int>>& vec) {
        x = vec.begin();
        y = vec.end();
        while (x != y && x->size() == 0) {
            x++;
        }
        if (x == y) return;
        z = x->begin();
    }
    
    int next() {
        hasNext();
        return *z++;
    }
    
    bool hasNext() {
        while (x != y && z == x->end()) {
            x++;
            if (x == y) break;
            z = x->begin();
        }
        if (x == y) return false;
        else return true;
    }
};

/**
 * Your Vector2D object will be instantiated and called as such:
 * Vector2D* obj = new Vector2D(vec);
 * int param_1 = obj->next();
 * bool param_2 = obj->hasNext();
 */