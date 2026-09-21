class Solution {
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        long long const MOD = 1e9 + 7;

        // Adjacency list: {neighbor, time} using long long for weight
        vector<vector<pair<int, long long>>> adj(n);
        for (const auto& it : roads) {
            adj[it[0]].push_back({it[1], it[2]});
            adj[it[1]].push_back({it[0], it[2]});
        }

        vector<long long> dist(n, LLONG_MAX);
        vector<long long> ways(n, 0);

        // Min-heap: {distance, node}
        priority_queue<pair<long long, int>, 
                       vector<pair<long long, int>>, 
                       greater<pair<long long, int>>> pq;

        dist[0] = 0;
        ways[0] = 1;
        pq.push({0, 0});

        while (!pq.empty()) {
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();


            for (const auto& it : adj[node]) {
                int adjnode = it.first;
                long long edw = it.second;

                // Found a shorter path
                if (dis + edw < dist[adjnode]) {
                    dist[adjnode] = dis + edw;
                    ways[adjnode] = ways[node];
                    pq.push({dist[adjnode], adjnode});
                }
                // Found an additional shortest path
                else if (dis + edw == dist[adjnode]) {
                    ways[adjnode] = (ways[adjnode] + ways[node]) % MOD;
                }
            }
        }

        return ways[n - 1] % MOD;
    }
};