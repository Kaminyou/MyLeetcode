class NumberContainers {
public:
    unordered_map<int, int> index2num;
    unordered_map<int, set<int>> num2indices;
    NumberContainers() {
        
    }
    
    void change(int index, int number) {
        if (index2num.find(index) != index2num.end()) {
            int prevNum = index2num[index];
            num2indices[prevNum].erase(index);
        }
        index2num[index] = number;
        num2indices[number].insert(index);
    }
    
    int find(int number) {
        if (num2indices.find(number) == num2indices.end()) return -1;
        if (num2indices[number].size() == 0) return -1;
        return *(num2indices[number].begin());
    }
};

/**
 * Your NumberContainers object will be instantiated and called as such:
 * NumberContainers* obj = new NumberContainers();
 * obj->change(index,number);
 * int param_2 = obj->find(number);
 */