class DSU {
public:
    vector<int> parent, size;

    DSU(int n) {
        parent.resize(n + 1);
        size.resize(n + 1);

        for (int i = 0; i < n; i++) {
            parent[i] = i;
            size[i] = 1;
        }
    }
    int findulp(int node) {
        if (parent[node] == node)
            return node;
        return parent[node] = findulp(parent[node]);
    }

    bool unionbysize(int u, int v) {
        int ulp_u = findulp(u);
        int ulp_v = findulp(v);

        if (ulp_u == ulp_v)
            return false;
        if (size[ulp_v] > size[ulp_u]) {
            size[ulp_v] += size[ulp_u];
            parent[ulp_u] = ulp_v;
        } else {
            size[ulp_u] += size[ulp_v];
            parent[ulp_v] = ulp_u;
        }
        return true;
    }
};
class Solution {
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        int n = edges.size(); // no.of nodes
        DSU ds(n);

        for (auto edge : edges) {
            if (ds.unionbysize(edge[0], edge[1]) == false)
                return edge;
        }

        return {};
    }
};