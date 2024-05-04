class Solution {
public:
    double toKelvin(double celsius) {
        return celsius + 273.15;
    }
    double toFahrenheit(double celsius) {
        return celsius * 1.8 + 32.0;
    }
    vector<double> convertTemperature(double celsius) {
        return {toKelvin(celsius), toFahrenheit(celsius)};
    }
};