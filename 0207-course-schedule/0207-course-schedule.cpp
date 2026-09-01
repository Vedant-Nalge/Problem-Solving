class Solution {
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<vector<int>> adj(numCourses);
        vector<int> indegree(numCourses); // from -> to indegree[to]

        for(auto it : prerequisites){
            int course = it[0];
            int prereq = it[1];
            adj[prereq].push_back(course);
            indegree[course]++;

        }

       

        queue<int> q;

        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] == 0) {
                q.push(i);
            }
        }

        while (!q.empty()) {
            int node = q.front();
            q.pop();

            for (auto it : adj[node]) {
                indegree[it]--;
                if (indegree[it] == 0)
                    q.push(it);
            }
        }

        for (int i = 0; i < indegree.size(); i++) {
            if (indegree[i] != 0)
                return false;
        }

        return true;
    }
};