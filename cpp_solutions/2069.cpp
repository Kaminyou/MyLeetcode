class Robot {
public:
    int w;
    int h;
    int steps;
    int now;
    int blocks;
    Robot(int width, int height) {
        blocks = width * 2 + height * 2 - 4;
        w = width;
        h = height;
        steps = 0;
        now = 0;
    }
    
    void step(int num) {
        steps += 1;
        now += num;
        now %= blocks;
    }
    
    vector<int> getPos() {
        if (now <= w - 1) return {now, 0};
        else if (now <= w + h - 2) return {w - 1, now - w + 1};
        else if (now <= w * 2 + h - 3) return {w - 1 - (now - (w + h - 2)), h - 1};
        else return {0, h - 1 - (now - (w * 2 + h - 3))};
    }
    
    string getDir() {
        if (steps == 0) return "East";
        if (now == 0) return "South";
        if (now <= w - 1) return "East";
        else if (now <= w + h - 2) return "North";
        else if (now <= w * 2 + h - 3) return "West";
        else return "South";
    }
};

/**
 * Your Robot object will be instantiated and called as such:
 * Robot* obj = new Robot(width, height);
 * obj->step(num);
 * vector<int> param_2 = obj->getPos();
 * string param_3 = obj->getDir();
 */
