class SnapShotArray {
public:
    vector<vector<int>> snapshots; // index -> {snapshot_i}
    vector<vector<int>> values; // index -> value at i snapshot
    int currentSnapID;
    
    SnapShotArray(int size) {
        snapshots.resize(size, vector<int>({0}));
        values.resize(size, vector<int>({0}));
        currentSnapID = 0;
    }
    void snap() {
        currentSnapID++;
    }
    int get(int index, int snapID) {
        int p = upper_bound(snapshots[index].begin(), snapshots[index].end(), snapID) - snapshots[index].begin() - 1;
        return values[index][p];
    }
    void set(int index, int value) {
        if (currentSnapID == snapshots[index].back()) {
            values[index][values[index].size() - 1] = value;
            return;
        }
        snapshots[index].push_back(currentSnapID);
        values[index].push_back(value);
    }
};

class SnapShotDisjointSet: public SnapShotArray {
public:
    SnapShotDisjointSet(int n) : SnapShotArray(n) {
        for (int i = 0; i < n; ++i) {
            set(i, -1);
        }
    }
    
    int find(int x, int snapID) {
        int pX = get(x, snapID);
        if (pX < 0) return x;
        return find(pX, snapID);
    }
    void merge(int x, int y) {
        int pX = find(x, currentSnapID);
        int pY = find(y, currentSnapID);
        if (pX == pY) return;
        int sX = -get(pX, currentSnapID);
        int sY = -get(pY, currentSnapID);
        if (sX >= sY) {
            set(pX, -sX - sY);
            set(pY, pX);
        }
        else {
            set(pY, -sY - sX);
            set(pX, pY);
        }
    }
    bool checkIsConnect(int x, int y, int snapID) {
        int pX = find(x, snapID);
        int pY = find(y, snapID);
        return pX == pY;
    }
};

class DistanceLimitedPathsExist {
public:
    SnapShotDisjointSet* snapShotDisjointSet;
    vector<int> lengthRecords;
    static bool compare(const vector<int>& v1, const vector<int>& v2) {
        return v1[2] < v2[2];
    }
    DistanceLimitedPathsExist(int n, vector<vector<int>>& edgeList) {
        sort(edgeList.begin(), edgeList.end(), compare);
        snapShotDisjointSet = new SnapShotDisjointSet(n);
        int currentLength = 0;
        for (auto& edge : edgeList) {
            if (edge[2] > currentLength) {
                lengthRecords.push_back(currentLength);
                currentLength = edge[2];
                snapShotDisjointSet->snap();
            }
            snapShotDisjointSet->merge(edge[0], edge[1]);
        }
        
        snapShotDisjointSet->snap();
        lengthRecords.push_back(currentLength);
    }
    
    bool query(int p, int q, int limit) {
        int recordID = lower_bound(lengthRecords.begin(), lengthRecords.end(), limit) - lengthRecords.begin() - 1;
        return snapShotDisjointSet->checkIsConnect(p, q, recordID);
    }
};

/**
 * Your DistanceLimitedPathsExist object will be instantiated and called as such:
 * DistanceLimitedPathsExist* obj = new DistanceLimitedPathsExist(n, edgeList);
 * bool param_1 = obj->query(p,q,limit);
 */