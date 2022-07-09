class Solution {
public:
    int latestTimeCatchTheBus(vector<int>& buses, vector<int>& passengers, int capacity) {
        sort(buses.begin(), buses.end());
        sort(passengers.begin(), passengers.end());
        
        unordered_set<int> passengerHash(passengers.begin(), passengers.end());
        
        int busSize = buses.size();
        int passengerSize = passengers.size();
        
        int res = 1;
        int passengerIdx = 0;
        int count = 0;
        
        // iterate each bus
        for (int busIdx = 0; busIdx < busSize; ++busIdx) {
            // fill each bus greedily
            while (passengerIdx < passengerSize && count < capacity && passengers[passengerIdx] <= buses[busIdx]) {
                // update res if passengers[passengerIdx] - 1 not existing
                if (passengerHash.find(passengers[passengerIdx] - 1) == passengerHash.end()) {
                    res = passengers[passengerIdx] - 1;
                }
                passengerIdx++;
                count++;
            }
            // if the current bus is not full and the last passenger is not equal to departing time
            // update res
            if (count < capacity && (passengerIdx == 0 || passengers[passengerIdx - 1] < buses[busIdx])) {
                res = buses[busIdx];
            }
            count = 0;
        }
        return res;
    }
};