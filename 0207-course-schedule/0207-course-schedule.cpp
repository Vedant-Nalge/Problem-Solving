class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        //create adj

        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses);


        int n = prerequisites.size();

        for(int i =0;i<n;i++){
            int u = prerequisites[i][1];
            int v = prerequisites[i][0];
            adj[u].push_back(v);
            indegree[v]++;
        }


        queue<int>q;

        for(int i =0;i<indegree.size();i++){
            if(indegree[i]==0){
                q.push(i);
            }
        }
            int ans = 0;
        while(!q.empty()){
            int node = q.front();
            q.pop();
            ans++;
            for ( auto it : adj [node]){
                indegree[it]--;
                if( indegree[it]==0){
                    q.push(it);
                }

            }
        }

        return (ans==numCourses);
        
    }
};