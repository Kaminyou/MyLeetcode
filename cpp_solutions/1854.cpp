class Solution {
public:
    int maximumPopulation(vector<vector<int>>& logs) {
        map<int, int> mp;
        for (auto& log : logs) {
            mp[log[0]]++;
            mp[log[1]]--;
        }
        int currPeople = 0;
        int maxPeople = 0;
        int year = -1;
        for (auto& element : mp) {
            currPeople += element.second;
            if (currPeople > maxPeople) {
                maxPeople = currPeople;
                year = element.first;
            }
        }
        return year;
    }
};