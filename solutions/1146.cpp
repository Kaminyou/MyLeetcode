class SnapshotArray {
public:
    unordered_map<int, map<int, int>> snapshot; // index -> {snapshot id, value}
    int snapshowIdx;
    SnapshotArray(int length) {
        snapshowIdx = 0;
        for (int i = 0; i < length; ++i) {
            snapshot[i][snapshowIdx] = 0;
        }
    }
    
    void set(int index, int val) {
        snapshot[index][snapshowIdx] = val;
    }
    
    int snap() {
        snapshowIdx++;
        return snapshowIdx - 1;
    }
    
    int get(int index, int snap_id) {
        auto it = snapshot[index].upper_bound(snap_id);
        it = prev(it);
        return it->second;
    }
};

/**
 * Your SnapshotArray object will be instantiated and called as such:
 * SnapshotArray* obj = new SnapshotArray(length);
 * obj->set(index,val);
 * int param_2 = obj->snap();
 * int param_3 = obj->get(index,snap_id);
 */