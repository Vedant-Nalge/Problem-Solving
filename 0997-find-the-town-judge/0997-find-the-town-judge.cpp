class Solution {
public:
    int findJudge(int n, vector<vector<int>>& trust) {
        vector<vector<int>> adj(n+1);
        unordered_map<int,int> p;
        for (auto it : trust) {
            int u = it[0];
            int v = it[1];
            adj[u].push_back(v);
            p[v]++;
        }

        for (int i = 1; i<=n ; i++) {
            if (adj[i].size() == 0 && p[i]==n-1) {
                return i;
                break;
            }
        }
        return -1;
    }
};