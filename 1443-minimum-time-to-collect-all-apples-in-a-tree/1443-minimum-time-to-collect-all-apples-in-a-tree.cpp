class Solution {
public:
    int helper(int src, int parent, vector<vector<int>>& adj,
               vector<bool>& hasApple) {
        int totaltime = 0;
        for (auto child : adj[src]) {
            if (child == parent)
                continue;

            int childtime = helper(child, src, adj, hasApple);

            if (childtime > 0 || hasApple[child]) {
                totaltime += 2 + childtime;
            }
        }
        return totaltime;
    }
    int minTime(int n, vector<vector<int>>& edges, vector<bool>& hasApple) {
        vector<vector<int>> adj(n);
        for (auto it : edges) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            adj[v].push_back(u);
        }

        return helper(0, -1, adj, hasApple);
    }
};