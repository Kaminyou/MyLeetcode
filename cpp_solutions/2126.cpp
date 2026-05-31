class Solution {
public:
    bool asteroidsDestroyed(int mass, vector<int>& asteroids) {
        sort(asteroids.begin(), asteroids.end());
        long long curr = mass;
        for (auto& asteroid : asteroids) {
            if (asteroid > curr) return false;
            curr += asteroid;
        }
        return true;
    }
};

