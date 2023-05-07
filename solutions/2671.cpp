class FrequencyTracker {
public:
    unordered_map<int, int> counts;
    unordered_map<int, int> frequencies;
    FrequencyTracker() {
        
    }
    
    void add(int number) {
        int freq = counts[number];
        counts[number]++;
        int postFreq = counts[number];
        if (freq > 0) frequencies[freq]--;
        frequencies[postFreq]++;
    }
    
    void deleteOne(int number) {
        int freq = counts[number];
        if (freq == 0) return;
        counts[number]--;
        int postFreq = counts[number];
        frequencies[freq]--;
        if (postFreq > 0) frequencies[postFreq]++;
    }
    
    bool hasFrequency(int frequency) {
        return frequencies[frequency] > 0;
    }
};

/**
 * Your FrequencyTracker object will be instantiated and called as such:
 * FrequencyTracker* obj = new FrequencyTracker();
 * obj->add(number);
 * obj->deleteOne(number);
 * bool param_3 = obj->hasFrequency(frequency);
 */