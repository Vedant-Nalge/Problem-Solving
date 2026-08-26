class Solution {
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        vector<vector<pair<int,int>>> adj(n);

        for(auto it : flights){
             int from = it[0] ;
             int to =it[1];
             int w = it[2];

             adj[from].push_back({to,w});
        }  
        vector<int> dist(n,INT_MAX);
        dist[src] =0;
    

        priority_queue<pair<int,pair<int,int>>,
        vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>> pq;

        pq.push({0,{src,0}}); // stops,node,dist;

        while(!pq.empty()){
            auto it = pq.top();
             int stops = it.first;
            int node =it.second.first;
            int cost = it.second.second;

            pq.pop();

            if(stops>k) continue;

            for(auto it :adj[node]){
                int adjnode = it.first;
                int edw =it.second;

                if(cost+edw<dist[adjnode] && stops<=k){
                    dist[adjnode] = cost + edw;

                    pq.push({stops+1,{adjnode,dist[adjnode]}});

                }
            }

        }
        if(dist[dst]==INT_MAX) return -1;
        return dist[dst];

    }
};