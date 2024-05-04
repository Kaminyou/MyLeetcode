class Solution {
public:
    int minNumberOfHours(int initialEnergy, int initialExperience, vector<int>& energy, vector<int>& experience) {
        // energy
        int sum = 0;
        for (auto& num : energy) sum += num;
        sum += 1;
        int plusEnergy = max(0, sum - initialEnergy);
        
        // exp
        int currExp = initialExperience;
        int plusExp = 0;
        for (auto& num : experience) {
            int need = (num + 1) - currExp;
            plusExp = max(plusExp, need);
            currExp += num;
        }
        return plusExp + plusEnergy;
    }
};