class ZigzagIterator {
public:
    vector<vector<int>*> v;
    queue<pair<int, int>> q;
    ZigzagIterator(vector<int>& v1, vector<int>& v2) {
        if (v1.size() > 0) q.push(make_pair(0, 0));
        if (v2.size() > 0) q.push(make_pair(1, 0));
        v.push_back(&v1);
        v.push_back(&v2);
    }

    int next() {
        auto [vIdx, loc] = q.front();
        q.pop();
        if (loc + 1 != v[vIdx]->size()) q.push(make_pair(vIdx, loc + 1));
        return (*v[vIdx])[loc];
    }

    bool hasNext() {
        return (q.size() > 0);
    }
};

/**
 * Your ZigzagIterator object will be instantiated and called as such:
 * ZigzagIterator i(v1, v2);
 * while (i.hasNext()) cout << i.next();
 */