class Solution {
public:
    int tree[400005] = {0};
    bool lazy[400005] = {false};
    void toggle(int node, int st, int en, int us, int ue) {
        if (lazy[node]) {
            lazy[node] = false;
            tree[node] = en - st + 1 - tree[node];

            if (st < en) {
                lazy[node << 1] = !lazy[node << 1];
                lazy[1 + (node << 1)] = !lazy[1 + (node << 1)];
            }
        }

        if (st > en || us > en || ue < st) return;
        if (us <= st && en <= ue) {
            tree[node] = en-st+1 - tree[node];

            if (st < en) {
                lazy[node << 1] = !lazy[node << 1];
                lazy[1 + (node << 1)] = !lazy[1 + (node << 1)];
            }
            return;
        }

        int mid = (st+en) / 2;
        toggle((node << 1), st, mid, us, ue);
        toggle((node << 1) + 1, mid + 1,en, us, ue);

        if (st < en)
            tree[node] = tree[node << 1] + tree[(node << 1) + 1];
    }

    int countQuery(int node, int st, int en, int qs, int qe) {
        if (st > en || qs > en || qe < st) return 0;
        if (lazy[node]) {
            lazy[node] = false;
            tree[node] = en - st + 1 - tree[node];
            if (st<en) {
                lazy[node<<1] = !lazy[node<<1];
                lazy[(node<<1)+1] = !lazy[(node<<1)+1];
            }
        }
        if (qs <= st && en <= qe) return tree[node];
        int mid = (st + en) / 2;
        return countQuery((node << 1), st, mid, qs, qe) + countQuery((node << 1) + 1, mid + 1, en, qs, qe);
    }
    vector<long long> handleQuery(vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& queries) {
        int N = nums1.size();

        int index = 0;
        while (index < N) {
            if (nums1[index] == 1) {
                int start = index;
                while (index + 1 < N && nums1[index + 1] == 1) {
                    index++;
                }
                toggle(1, 0, N - 1, start, index);
            }
            index++;
        }
        
        vector<long long> res;

        long long sum = 0;
        for (auto& num : nums2) sum += num;
        int m = queries.size();
        for (int i = 0; i < m; ++i) {
            if (queries[i][0] == 1) {
                toggle(1, 0, N - 1, queries[i][1], queries[i][2]);
            }
            else if (queries[i][0] == 2) {
                long long current = countQuery(1, 0, N - 1, 0, N - 1);
                sum += current * queries[i][1];
            }
            else {
                res.push_back(sum);
            }
        }
        return res;
    }
};