const int primes[65] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 
    53, 59, 61, 67, 71, 73, 79, 83, 89, 97, 101, 103, 107, 109, 113, 127, 131, 
    137, 139, 149, 151, 157, 163, 167, 173, 179, 181, 191, 193, 197, 199, 211, 223, 
    227, 229, 233, 239, 241, 251, 257, 263, 269, 271, 277, 281, 283, 293, 307, 311, 313};

class DisjointSet {
public:
    vector<int> parents;
    vector<int> ranks;
    DisjointSet(int size) {
        parents.resize(size + 1, 0);
        for (int i = 0; i < size + 1; ++i) parents[i] = i;
        ranks.resize(size + 1, 1);
    }
    int find(int x) {
        if (parents[x] != x) {
            parents[x] = find(parents[x]);
        }
        return parents[x];
    }
    void join(int x, int y) {
        int pX = find(x);
        int pY = find(y);
        if (pX == pY) return;
        if (ranks[pX] > ranks[pY]) {
            parents[pY] = pX;
        }
        else if (ranks[pX] < ranks[pY]) {
            parents[pX] = pY;
        }
        else {
            ranks[pX]++;
            parents[pY] = pX;
        }
    }
};
class Solution {
public:
    vector<int> factorize(int n) {
        vector<int> facts;
        for (int p : primes)
            if (n % p == 0) {
                facts.push_back(p);
                while(n % p == 0)
                    n /= p;
            }
        if (n != 1) // Some large prime
            facts.push_back(n);
        return facts;
    }
    bool canTraverseAllPairs(vector<int>& nums) {
        int numOneCnt = 0;
        for (auto num : nums) {
            if (num == 1) numOneCnt++;
            if (numOneCnt > 1) return false;
        }
        int maxValue = *max_element(nums.begin(), nums.end());
        DisjointSet* disjointSet = new DisjointSet(maxValue);
        for (auto num : nums) {
            for (auto f : factorize(num)) {
                disjointSet->join(num, f);
            }
        }
        unordered_set<int> parents;
        for (auto num : nums) {
            int parent = disjointSet->find(num);
            parents.insert(parent);
        }
        return parents.size() == 1;
    }
};