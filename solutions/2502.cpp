class Allocator {
public:
    vector<int> memory;
    int N;
    Allocator(int n) {
        memory.resize(n, 0);
        this->N = n;
    }
    
    int allocate(int size, int mID) {
        int index = 0;
        while (index < N) {
            if (memory[index] == 0) {
                int start = index;
                while (index + 1 < N && memory[index + 1] == 0 && index - start + 1 < size) {
                    index++;
                }
                if (index - start + 1 >= size) {
                    for (int i = 0; i < size; ++i) {
                        memory[start + i] = mID;
                    }
                    return start;
                }
            }
            index++;
        }
        return -1;
    }
    
    int free(int mID) {
        int cnt = 0;
        for (int i = 0; i < N; ++i) {
            if (memory[i] == mID) {
                cnt++;
                memory[i] = 0;
            }
        }
        return cnt;
    }
};

/**
 * Your Allocator object will be instantiated and called as such:
 * Allocator* obj = new Allocator(n);
 * int param_1 = obj->allocate(size,mID);
 * int param_2 = obj->free(mID);
 */