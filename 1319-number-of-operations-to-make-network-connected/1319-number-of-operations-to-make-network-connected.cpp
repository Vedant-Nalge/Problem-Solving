class DisjointSet {

public:
    vector<int> parent, rank, size;
    DisjointSet(int n) {
        parent.resize(n + 1);
        rank.resize(n + 1, 0);
        size.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }

    int findUpar(int node) {
        if (parent[node] == node)
            return node;
        else
            return parent[node] = findUpar(parent[node]);
    }

    void unionbyrank(int u, int v) {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if (ulp_u == ulp_v)
            return;
        if (rank[ulp_u] >= rank[ulp_v])
            parent[ulp_v] = ulp_u;
        else
            parent[ulp_u] = ulp_v;
    }

    void unionbysize(int u, int v) {
        int ulp_u = findUpar(u);
        int ulp_v = findUpar(v);

        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] >= size[ulp_v]) {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        } else {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        }
    }
};

class Solution {
public:
    int makeConnected(int n, vector<vector<int>>& connections) {
        DisjointSet dsu(n);
        int cntextra = 0;

        for (auto it : connections) {
            int u = it[0];
            int v = it[1];

            if (dsu.findUpar(u) == dsu.findUpar(v))
                cntextra++;

            else {
                dsu.unionbyrank(u, v);
            }
        }

        int Nu = 0;
        for (int i = 0; i < n; i++) {
            if (dsu.parent[i] == i)
                Nu++;
        }

        int ans = Nu - 1;

        if (cntextra >= ans)
            return ans;
        else
            return -1;
    }
};