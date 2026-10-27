class Solution {
public:
    vector<string> findAllRecipes(vector<string>& recipes,
                                  vector<vector<string>>& ingredients,
                                  vector<string>& supplies) {
        int n = recipes.size();

        unordered_map<string, vector<string>> adj;

        unordered_map<string, int> indegree;

        for (int i = 0; i < recipes.size(); i++) {
             string r = recipes[i];
            indegree[r] = ingredients[i].size();

            for (string ing : ingredients[i]) {
                adj[ing].push_back(r);
            }
        }
        vector<string> ans;
        queue<string> q;
        for (auto it : supplies) {
            q.push(it);
        }
        while (!q.empty()) {
            string node = q.front();
            q.pop();
            if (adj.find(node) == adj.end())
                continue;
            for (auto it : adj[node]) {

                indegree[it]--;
                if (indegree[it] == 0) {
                    ans.push_back(it);
                    q.push(it);
                }
            }
        }
        return ans;
    }
};