class Solution {
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        int n = heights.size();
        int m = heights[0].size();

        priority_queue<pair<int,pair<int,int>>,vector<pair<int,pair<int,int>>>,greater<pair<int,pair<int,int>>>>pq;

        vector<vector<int>> dist(n,vector<int>(m,INT_MAX));

        dist[0][0] = 0;
        pq.push({0,{0,0}});  // dist,{r,c}

        int dr[] ={0,1,0,-1};
        int dc[] ={1,0,-1,0};


        while(!pq.empty()){
            auto it = pq.top();
            int r =it.second.first;
            int c =it.second.second;
            int diff = it.first;
            pq.pop();

            if(r==n-1 && c==m-1) return diff;
             for(int i =0 ;i<4;i++){
                int nr = r + dr[i];
                int nc = c+dc[i];

                if(nr>=0 && nr<n && nc>=0 && nc<m){
                    int neweffort = max(diff,abs(heights[r][c] -heights[nr][nc]));
                    if(neweffort < dist[nr][nc]) {
                        dist[nr][nc] = neweffort;
                        pq.push({neweffort,{nr,nc}});
                    }
                }
             }

        } 
        return 0;      
    }
};