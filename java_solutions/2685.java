class DisjointSet {
    private int[] parent;
    private int[] rank;
    private int[] nodes;

    public DisjointSet(int size) {
        parent = new int[size];
        rank = new int[size];
        nodes = new int[size];
        for (int i = 0; i < size; ++i) {
            parent[i] = i;
            nodes[i] = 1;
        }
    }

    public int find(int x) {
        if (parent[x] != x) {
            parent[x] = find(parent[x]); // Path compression
        }
        return parent[x];
    }

    public void join(int x, int y) {
        int pX = find(x);
        int pY = find(y);
        if (pX == pY) return;

        if (rank[pX] > rank[pY]) {
            parent[pY] = pX;
            nodes[pX] += nodes[pY];
        } else if (rank[pX] < rank[pY]) {
            parent[pX] = pY;
            nodes[pY] += nodes[pX];
        } else {
            parent[pY] = pX;
            nodes[pX] += nodes[pY];
            rank[pX]++;
        }
    }

    public int getNodes(int x) {
        return nodes[find(x)];
    }
}

class Solution {
    public int countCompleteComponents(int n, int[][] edges) {
        DisjointSet disjointSet = new DisjointSet(n);
        for (int[] edge : edges) {
            disjointSet.join(edge[0], edge[1]);
        }

        Map<Integer, Integer> parent2edgeCnt = new HashMap<>();
        for (int[] edge : edges) {
            int parent = disjointSet.find(edge[0]);
            parent2edgeCnt.put(parent, parent2edgeCnt.getOrDefault(parent, 0) + 1);
        }

        Set<Integer> seen = new HashSet<>();
        int res = 0;
        for (Map.Entry<Integer, Integer> entry : parent2edgeCnt.entrySet()) {
            int parent = entry.getKey();
            int cnt = entry.getValue();
            int nodes = disjointSet.getNodes(parent);
            seen.add(parent);
            if ((nodes * (nodes - 1)) / 2 == cnt) res++;
        }

        for (int i = 0; i < n; ++i) {
            int parent = disjointSet.find(i);
            if (!seen.contains(parent) && disjointSet.getNodes(i) == 1) {
                seen.add(parent);
                res++;
            }
        }

        return res;
    }
}
