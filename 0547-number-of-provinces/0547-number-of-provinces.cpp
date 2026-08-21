class Solution {
public:
    void  dfs(int i ,vector<vector<int>>& isConnected,vector<int> & vis,int n){
        vis[i] =1;
        for(int j =0;j<n;j++){
            if(isConnected[i][j]==1 && vis[j] == 0){
                dfs(j,isConnected,vis,n);
            }
        }
    }
    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        vector<int> vis(n+1);
        int provinces = 0;
        
        for(int i =0 ; i < n ;i++){
            if(vis[i]==0){
                provinces++;
                dfs(i,isConnected,vis,n);
            }
        }
        return provinces;
    }
};