class Solution {
public:
    double square;
    double x_center;
    double y_center;
    Solution(double radius, double x_center, double y_center) {
        square = radius * radius;
        this->x_center = x_center;
        this->y_center = y_center;
    }
    
    double randomDouble(double minVal, double maxVal) {
        return (maxVal - minVal) * ((double)rand() / (double)RAND_MAX) + minVal;
    }
    vector<double> randPoint() {
        double randSquare = randomDouble(0, square);
        double randLength = sqrt(randSquare);
        
        double randomDegree = randomDouble(0, 360);
        double randomRad = randomDegree * 3.14159 / 180.0;
        
        double x = cos(randomRad) * randLength + x_center;
        double y = sin(randomRad) * randLength + y_center;
        return {x, y};
    }
};

/**
 * Your Solution object will be instantiated and called as such:
 * Solution* obj = new Solution(radius, x_center, y_center);
 * vector<double> param_1 = obj->randPoint();
 */