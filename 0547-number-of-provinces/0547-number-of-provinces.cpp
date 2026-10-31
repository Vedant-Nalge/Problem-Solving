class DSU {

public:
    vector<int> parent, size;
    DSU(int n) {
        size.resize(n + 1);
        parent.resize(n + 1);
        for (int i = 0; i <= n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findulp(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findulp(parent[node]);
    }

    void unionbysize(int u, int v) {
        int ulp_u = findulp(u);
        int ulp_v = findulp(v);

        if (ulp_u == ulp_v)
            return;
        if (size[ulp_u] < size[ulp_v]) {
            parent[ulp_u] = ulp_v;
            size[ulp_v] += size[ulp_u];
        } else {
            parent[ulp_v] = ulp_u;
            size[ulp_u] += size[ulp_v];
        }
    }
};

class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        DSU ds(n);

        for (int i = 0; i < n; i++) {
            for (int j = 0; j < n; j++) {
                if (isConnected[i][j] == 1) {
                    ds.unionbysize(i, j);
                }
            }
        }

        int provinces = 0;
        for (int i = 0; i < n; i++) {
            if (ds.parent[i] == i) {
                provinces++;
            }
        }

        return provinces;
    }
};