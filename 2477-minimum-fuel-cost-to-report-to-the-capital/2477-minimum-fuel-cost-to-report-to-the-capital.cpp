class Solution {
public:
    long long minimumFuelCost(vector<vector<int>>& roads, int seats) {
        int n = roads.size();
        vector<int> degree(n + 1, 0);
        vector<vector<int>> adj(n + 1);
        vector<long long> people(n + 1, 1);
        for (auto it : roads) {
            int a = it[0];
            int b = it[1];
            adj[a].push_back(b);
            adj[b].push_back(a);
            degree[a]++;
            degree[b]++;
        }
        queue<int> q;
        for (int i = 1; i < n+1; i++) {
            if (degree[i] == 1)
                q.push(i);
        }

        long long fuel = 0;

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : adj[node]) {
                if (degree[it] == 0)
                    continue;

                fuel += (people[node] + seats - 1) / seats;
                people[it] += people[node];

                degree[node] = 0;
                degree[it]--;

                if (it != 0 && degree[it] == 1) {
                    q.push(it);
                }
               
            }
        }
        return fuel;
    }
};