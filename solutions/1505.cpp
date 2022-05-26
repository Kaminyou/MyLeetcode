class BIT {
private:
    vector<int> tree;
public:
    BIT(int size) {
        tree.resize(size + 1, 0);
    }
    int lsb(int x) {
        return x & (-x);
    }
    void update(int index, int x) {
        index += 1;
        while(index < tree.size()) {
            tree[index] += x;
            index += lsb(index);
        }
    }
    int query(int index) {
        index += 1;
        int sum = 0;
        while (index) {
            sum += tree[index];
            index -= lsb(index);
        }
        return sum;
    }
};
class Solution {
public:
    string minInteger(string num, int k) {
        int n = num.size();
        vector<queue<int>> q(10);
        for (int i = 0; i < n; ++i) {
            q[num[i] - '0'].push(i);
        }
        vector<bool> seen(n, false);
        BIT* bit = new BIT(n);
        string ans;
        while (k > 0 && ans.size() < n) {
            for (int i = 0; i < 10; ++i) {
                if (q[i].empty()) continue;
                int index = q[i].front();
                int move = index - bit->query(index - 1);
                if (move > k) continue;
                q[i].pop();
                k -= move;
                bit->update(index, 1);
                ans.push_back(i + '0');
                seen[index] = true;
                break;
            }
        }
        for (int i = 0; i < n; ++i) {
            if (!seen[i]) ans.push_back(num[i]);
        }
        return ans;
    }
};