class Solution {
public:
    bool validPath(int n, vector<vector<int>>& edges, int source,
                   int destination) {
        if (source == destination)
            return true;
        vector<vector<int>> adj(n);

        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            adj[v].push_back(u);
            adj[u].push_back(v);
        }
        queue<int> q;
        vector<bool> visited(n, false);
        q.push(source);
        visited[source] = true;
        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : adj[node]) {
                if (it == destination)
                    return true;
                if (!visited[it]) {
                    q.push(it);
                    visited[it] = true;
                }
            }
        }
        return false;
    }
};
