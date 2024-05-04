class SegmentTree {
private:
    int M;
    vector<vector<long long>> tree; // max, sum
public:
    SegmentTree(int n, int m) {
        M = m;
        tree.resize(n, vector<long long>(2, 0));
    }
    void build(int i, int p, int q, int m) {
        if (p == q) {
            tree[i] = {m, m};
            return;
        }
        int r = p + (q - p) / 2;
        tree[i] = {m, m * (long long)(q - p + 1)};
        build(i * 2 + 1, p, r, m);
        build(i * 2 + 2, r + 1, q, m);
    }
    vector<int> queryMax(int i, int p, int q, int maxRow, int k) {
        if (p > maxRow) return {};
        if (tree[i][0] < k) return {};
        if (p == q) return {p, (int)(M - tree[i][0])};
        int r = p + (q - p) / 2;
        vector<int> ret = queryMax(i * 2 + 1, p, r, maxRow, k);
        if (ret.size() > 0) {
            return ret;
        }
        return queryMax(i * 2 + 2, r + 1, q, maxRow, k);
    }
    void updateMax(int i, int p, int q, int target, int k) {
        if (p > target) return;
        if (q < target) return;
        if (p == q) {
            tree[i][0] -= k;
            tree[i][1] -= k;
            return;
        }
        int r = p + (q - p) / 2;
        tree[i][1] -= k;
        updateMax(i * 2 + 1, p, r, target, k);
        updateMax(i * 2 + 2, r + 1, q, target, k);
        tree[i][0] = max(tree[i * 2 + 1][0], tree[i * 2 + 2][0]);
    }
    long long querySum(int i, int p, int q, int maxRow) {
        if (p > maxRow) return 0;
        if (q <= maxRow) return tree[i][1];
        int r = p + (q - p) / 2;
        return querySum(i * 2 + 1, p, r, maxRow) + querySum(i * 2 + 2, r + 1, q, maxRow);
    }
    void updateSum(int i, int p, int q, int maxRow, int k) {
        if (p > maxRow) return;
        if (p == q) {
            tree[i][0] -= k;
            tree[i][1] -= k;
            return;
        }
        int r = p + (q - p) / 2;
        tree[i][1] -= k;
        if (r + 1 > maxRow || tree[i * 2 + 1][1] >= k) {
            updateSum(i * 2 + 1, p, r, maxRow, k);
        }
        else {
            k -= tree[i * 2 + 1][1];
            updateSum(i * 2 + 1, p, r, maxRow, tree[i * 2 + 1][1]);
            updateSum(i * 2 + 2, r + 1, q, maxRow, k);
        }
        tree[i][0] = max(tree[i * 2 + 1][0], tree[i * 2 + 2][0]);
    }
    
    
};
class BookMyShow {
public:
    int N;
    SegmentTree* segmentTree;
    BookMyShow(int n, int m) {
        N = n;
        int size = 1;
        while (size < 2 * n) {
            size <<= 1;
        }
        segmentTree = new SegmentTree(size, m);
        segmentTree->build(0, 0, N - 1, m);
    }
    
    vector<int> gather(int k, int maxRow) {
        vector<int> res = segmentTree->queryMax(0, 0, N - 1, maxRow, k);
        if (res.size() > 0) {
            segmentTree->updateMax(0, 0, N - 1, res[0], k);
        }
        return res;
    }
    
    bool scatter(int k, int maxRow) {
        long long sum = segmentTree->querySum(0, 0, N - 1, maxRow);
        if (sum >= k) {
            segmentTree->updateSum(0, 0, N - 1, maxRow, k);
        }
        return sum >= k;
    }
};

/**
 * Your BookMyShow object will be instantiated and called as such:
 * BookMyShow* obj = new BookMyShow(n, m);
 * vector<int> param_1 = obj->gather(k,maxRow);
 * bool param_2 = obj->scatter(k,maxRow);
 */